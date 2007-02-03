#ifndef NEWAGE_SCENEPLAYER_H_
#define NEWAGE_SCENEPLAYER_H_

#include "cfg.h"
#include <memory>
#include <mutant/mutant.h>
#include <mutant/io_factory.h>
#include <mutant/reader.h>

#include <mutalisk/array.h>
#include <mutalisk/platform.h>
#include <mutalisk/mutalisk.h>

#include "animator/Animators.h"
#include "animator/AnimatorAlgos.h"

#ifndef AP
#define AP_DEFINED_LOCALY
#define AP std::auto_ptr
#endif

struct RenderableMesh;
struct RenderableTexture;
struct CSkinnedAlgos
{
	typedef std::vector<std::pair<int, int> > BoneMapT;
	static void processSkinMesh(RenderableMesh& mesh, BoneMapT const& boneMap, CTransform::t_matrix const* data);
	static void processSkinMesh(Vec3 const* srcPositions, Vec3 const* srcNormals, float const* srcWeights, unsigned char const* srcBoneIndices,
		Vec3 *dstPositions, Vec3* dstNormals,
		size_t srcVertexStride, size_t srcWeightStride, size_t srcBoneIndexStride, size_t dstVertexStride, size_t vertexCount,
		mutalisk::data::skin_info const& skinInfo, BoneMapT const& boneMap, CTransform::t_matrix const* matrixData);
};

struct RenderableScene
{
	struct SharedResources {
		struct Mesh {
			AP<mutalisk::data::mesh>	blueprint;
			AP<RenderableMesh>			renderable;
		};
/*		struct Texture {
			AP<mutalisk::data::texture>	blueprint;
			AP<RenderableTexture>		renderable;
		};*/
		mutalisk::array<Mesh>			meshes;
		AP<mutant::anim_character_set>	animCharSet;
	};
	struct State {
		float							time;
		mutant::anim_character*			character;
		mutant::anim_hierarchy*			hierarchy;
		mutant::anim_clip*				clip;

//		BoneMapT						boneMap;
		CTransformArrayAnimator			xformArrayAnimator;

		typedef std::vector<CTransform> TransformsT;
		typedef std::vector<CTransform::t_matrix> MatricesT;
		TransformsT						transforms;
		MatricesT						matrices;

		std::vector<size_t>				light2XformIndex;
		std::vector<size_t>				camera2XformIndex;
		std::vector<size_t>				actor2XformIndex;

		typedef CSkinnedAlgos::BoneMapT	BoneMapT;
		std::vector<BoneMapT>			bone2XformIndex;


		void setClip(mutant::anim_character_set& animCharSet, unsigned int clipIndex, bool looping)
		{
			this->character = &animCharSet["scene"];
			ASSERT(this->character);
			this->hierarchy = &this->character->hierarchy(mutant::sTypeNames::HIERARCHY_DEFAULT);
			ASSERT(this->hierarchy);

			this->transforms.resize(this->hierarchy->size(), CTransform::identity());
			this->matrices.resize(this->hierarchy->size());

			if(clipIndex != ~0U)
			{
				this->clip = &(*this->character)[clipIndex];
				ASSERT(this->clip);
				this->xformArrayAnimator.createFromClip(
					*this->clip,
					*this->hierarchy,
					looping);
			}
			else
				this->clip = 0;

			this->time = 0.0f;
		}

		void updateDt(float deltaTime)
		{
			this->time += deltaTime;
			update(this->time);
		}

		void update(float time)
		{
			this->time = time;
			this->xformArrayAnimator.updateTransforms(this->time,
				this->transforms.begin(), this->transforms.end());
		}

		void process(SharedResources& sharedResources)	
		{
			ASSERT(this->hierarchy);
			CAnimatorAlgos::transformHierarchy(
				this->matrices.begin(), this->matrices.end(),
				this->transforms.begin(), *this->hierarchy );

			for(size_t q = 0; q < this->bone2XformIndex.size(); ++q)
				if( !this->bone2XformIndex[q].empty() )
				{
					ASSERT(sharedResources.meshes[q].renderable.get());
					CSkinnedAlgos::processSkinMesh(*sharedResources.meshes[q].renderable, this->bone2XformIndex[q], &this->matrices[0]);
				}
		}

	};

	RenderableScene(mutalisk::data::scene const& blueprint) : mBlueprint(blueprint) {}

	mutalisk::data::scene const&	mBlueprint;
	SharedResources					mResources;
	State							mState;

	template <typename Node>
	void mapNodesToHierarchy(mutant::anim_hierarchy const& hierarchy, Node	const* nodes, size_t nodeCount, std::vector<size_t>& node2XformIndex)
	{
		node2XformIndex.resize(nodeCount);
		for(size_t q = 0; q < nodeCount; ++q)
			node2XformIndex[q] = hierarchy.index_by_name(nodes[q].nodeName);
	}

	void mapBoneToHierarchy(mutant::anim_hierarchy const& hierarchy,
		mutalisk::data::skin_info::Bone* bones, size_t boneCount, State::BoneMapT& bone2XformIndex )
	{
		bone2XformIndex.reserve( boneCount );

		for( size_t q = 0; q < boneCount; ++q )
		{
			unsigned boneId = 0;
			std::string const& boneName = bones[q].name;

			while( boneId < hierarchy.size() && hierarchy[ boneId ].name != boneName )
				++boneId;

			if( boneId == hierarchy.size() )
				printf( "Couldn't find '%s' in hierarchy", boneName.c_str() );
			else
				bone2XformIndex.push_back( std::make_pair( (int)q, boneId ) );
		}
	}


	void setClip(unsigned int clipIndex, bool looping = true)
	{
		ASSERT(mResources.animCharSet.get());
		mState.setClip(*mResources.animCharSet, clipIndex, looping);

		ASSERT(mState.hierarchy);
		mapNodesToHierarchy(*mState.hierarchy, &mBlueprint.lights[0], mBlueprint.lights.size(), mState.light2XformIndex);
		mapNodesToHierarchy(*mState.hierarchy, &mBlueprint.cameras[0], mBlueprint.cameras.size(), mState.camera2XformIndex);
		mapNodesToHierarchy(*mState.hierarchy, &mBlueprint.actors[0], mBlueprint.actors.size(), mState.actor2XformIndex);
		
		mState.bone2XformIndex.resize(mBlueprint.meshIds.size());
		for(size_t q = 0; q < mBlueprint.meshIds.size(); ++q)
			if( mResources.meshes[q].blueprint->skinInfo )
				mapBoneToHierarchy(*mState.hierarchy,
					&mResources.meshes[q].blueprint->skinInfo->bones[0], mResources.meshes[q].blueprint->skinInfo->bones.size(),
					mState.bone2XformIndex[q]);
	}
	void update(float deltaTime) { mState.update(deltaTime); }
	void process() { mState.process(mResources); }
};

static AP<mutant::mutant_reader> createFileReader(std::string fileName)
{
	AP<mutant::binary_input> input = mutant::reader_factory::createInput(fileName);
	AP<mutant::mutant_reader> mutReader(new mutant::mutant_reader(input));
	mutReader->enableLog(false);

	return mutReader;
}

template <typename ResourceType>
static AP<ResourceType> loadResource(std::string fileName)
{
	AP<mutant::mutant_reader> reader = createFileReader(fileName);
	AP<ResourceType> resource(new ResourceType);
	;;printf("loadResource<>: $ %s\n", fileName.c_str());
	*reader >> *resource;
	;;printf("loadResource<>: ! %s\n", fileName.c_str());
	return resource;
}

template <>
static AP<mutant::anim_character_set> loadResource(std::string fileName)
{
	AP<mutant::mutant_reader> reader = createFileReader(fileName);
	AP<mutant::anim_character_set> resource(new mutant::anim_character_set);
	;;printf("loadResource<anim_character_set>: $ %s\n", fileName.c_str());
	reader->read(*resource);
	;;printf("loadResource<anim_character_set>: ! %s\n", fileName.c_str());
	return resource;
}

#ifdef AP_DEFINED_LOCALY
#undef AP
#endif

#endif // NEWAGE_SCENEPLAYER_H_