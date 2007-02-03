/*!  \file kfbxconstraintparent.h
 */

#ifndef _FBXSDK_CONSTRAINT_PARENT_H_
#define _FBXSDK_CONSTRAINT_PARENT_H_

/**************************************************************************************

 Copyright � 2001 - 2006 Autodesk, Inc. and/or its licensors.
 All Rights Reserved.

 The coded instructions, statements, computer programs, and/or related material
 (collectively the "Data") in these files contain unpublished information
 proprietary to Autodesk, Inc. and/or its licensors, which is protected by
 Canada and United States of America federal copyright law and by international
 treaties.

 The Data may not be disclosed or distributed to third parties, in whole or in
 part, without the prior written consent of Autodesk, Inc. ("Autodesk").

 THE DATA IS PROVIDED "AS IS" AND WITHOUT WARRANTY.
 ALL WARRANTIES ARE EXPRESSLY EXCLUDED AND DISCLAIMED. AUTODESK MAKES NO
 WARRANTY OF ANY KIND WITH RESPECT TO THE DATA, EXPRESS, IMPLIED OR ARISING
 BY CUSTOM OR TRADE USAGE, AND DISCLAIMS ANY IMPLIED WARRANTIES OF TITLE,
 NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE OR USE.
 WITHOUT LIMITING THE FOREGOING, AUTODESK DOES NOT WARRANT THAT THE OPERATION
 OF THE DATA WILL BE UNINTERRUPTED OR ERROR FREE.

 IN NO EVENT SHALL AUTODESK, ITS AFFILIATES, PARENT COMPANIES, LICENSORS
 OR SUPPLIERS ("AUTODESK GROUP") BE LIABLE FOR ANY LOSSES, DAMAGES OR EXPENSES
 OF ANY KIND (INCLUDING WITHOUT LIMITATION PUNITIVE OR MULTIPLE DAMAGES OR OTHER
 SPECIAL, DIRECT, INDIRECT, EXEMPLARY, INCIDENTAL, LOSS OF PROFITS, REVENUE
 OR DATA, COST OF COVER OR CONSEQUENTIAL LOSSES OR DAMAGES OF ANY KIND),
 HOWEVER CAUSED, AND REGARDLESS OF THE THEORY OF LIABILITY, WHETHER DERIVED
 FROM CONTRACT, TORT (INCLUDING, BUT NOT LIMITED TO, NEGLIGENCE), OR OTHERWISE,
 ARISING OUT OF OR RELATING TO THE DATA OR ITS USE OR ANY OTHER PERFORMANCE,
 WHETHER OR NOT AUTODESK HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH LOSS
 OR DAMAGE.

**************************************************************************************/

#include <kaydaradef.h>
#ifndef KFBX_DLL 
	#define KFBX_DLL K_DLLIMPORT
#endif

#include <kaydara.h>

#include <kfbxplugins/kfbxconstraint.h>
#include <kfbxplugins/kfbxgroupname.h>

#include <klib/kerror.h>

#include <fbxfilesdk_nsbegin.h>

class KFbxSdkManager;
class KFbxConstraintParent_internal;


/** \brief This constraint class contains methods for accessing the properties of a parent constraint.
  * A parent constraint lets you constrain the translation, scaling, rotation of an object based on one or more parent objects.
  * \nosubgrouping
  */
class KFBX_DLL KFbxConstraintParent : public KFbxConstraint
{
	KFBXOBJECT_DECLARE(KFbxConstraintParent);

		/**
		  * \name Properties
		  */
		//@{
			KFbxTypedProperty<fbxBool1>		Lock;
			KFbxTypedProperty<fbxBool1>		Active;

			KFbxTypedProperty<fbxBool1>		AffectTranslationX;
			KFbxTypedProperty<fbxBool1>		AffectTranslationY;
			KFbxTypedProperty<fbxBool1>		AffectTranslationZ;

			KFbxTypedProperty<fbxBool1>		AffectRotationX;
			KFbxTypedProperty<fbxBool1>		AffectRotationY;
			KFbxTypedProperty<fbxBool1>		AffectRotationZ;

			KFbxTypedProperty<fbxDouble1>	Weight;

			KFbxTypedProperty<fbxReference> ConstraintSources;
			KFbxTypedProperty<fbxReference> ConstrainedObject;
		//@}
public:
	/** Set the constraint lock.
	  * \param pLock     State of the lock flag.
	  */
	void SetLock(bool pLock);

	/** Retrieve the constraint lock state.
	  * \return Current lock flag.
	  */
	bool GetLock();

	/** Set the constraint active.
	  * \param pLock State of the active flag.
	  */
	void SetActive(bool pActive);

	/** Retrieve the constraint active state.
	  * \return Current active flag.
	  */
	bool GetActive();

	/** Set the constraint X-axe translation effectiveness.
	  * \param pAffect State of the translation effectivness on the X axe.
	  */
	void SetAffectTranslationX(bool pAffect);

	/** Retrieve the constraint X-axe translation effectiveness.
	  * \return Current state flag.
	  */
	bool GetAffectTranslationX();

	/** Set the constraint Y-axe translation effectiveness.
	  * \param pAffect State of the translation effectivness on the Y axe.
	  */
	void SetAffectTranslationY(bool pAffect);

	/** Retrieve the constraint Y-axe translation effectiveness.
	  * \return Current state flag.
	  */
	bool GetAffectTranslationY();

	/** Set the constraint Z-axe translation effectiveness.
	  * \param pAffect State of the translation effectivness on the Z axe.
	  */
	void SetAffectTranslationZ(bool pAffect);

	/** Retrieve the constraint Z-axe translation effectiveness.
	  * \return Current state flag.
	  */
	bool GetAffectTranslationZ();

	/** Set the constraint X-axe rotation effectiveness.
	  * \param pAffect State of the rotation effectivness on the X axe.
	  */
	void SetAffectRotationX(bool pAffect);

	/** Retrieve the constraint X-axe rotation effectiveness.
	  * \return Current state flag.
	  */
	bool GetAffectRotationX();

	/** Set the constraint Y-axe rotation effectiveness.
	  * \param pAffect State of the rotation effectivness on the Y axe.
	  */
	void SetAffectRotationY(bool pAffect);

	/** Retrieve the constraint Y-axe rotation effectiveness.
	  * \return Current state flag.
	  */
	bool GetAffectRotationY();

	/** Set the constraint Z-axe rotation effectiveness.
	  * \param pAffect State of the rotation effectivness on the Z axe.
	  */
	void SetAffectRotationZ(bool pAffect);

	/** Retrieve the constraint Z-axe rotation effectiveness.
	  * \return Current state flag.
	  */
	bool GetAffectRotationZ();

	/** Set the translation offset.
	  * \param Source object.
	  * \param New offset vector.
	  */
	void SetTranslationOffset(KFbxObject* pObject, KFbxVector4 pTranslation);

	/** Retrieve the constraint translation offset.
	  * \param Object that we want the offset.
	  * \return Current translation offset.
	  */
	KFbxVector4 GetTranslationOffset(KFbxObject* pObject);

	/** Set the rotation offset.
	  * \param Source object.
	  * \param New offset vector.
	  */
	virtual void SetRotationOffset(KFbxObject* pObject, KFbxVector4 pRotation);

	/** Retrieve the constraint rotation offset.
	  * \param Object that we want the offset.
	  * \return Current translation offset.
	  */
	KFbxVector4 GetRotationOffset(KFbxObject* pObject);

	/** Set the weight of the constraint.
	  * \param New weight value.
	  */
	void SetWeight(double pWeight);

	/** Get the weight of a source.
	  * \param Index of the source.
	  */
	double GetSourceWeight(KFbxObject* pObject);

	/** Add a source to the constraint.
	  * \param New source object.
	  * \param Weight of the source object.
	  */
	void AddConstraintSource(KFbxObject* pObject, double pWeight = 100);

	/** Retrieve the constraint source count.
	  * \return Current constraint source count.
	  */
	int GetConstraintSourceCount();

	/** Retrieve a constraint source object.
	  * \return Current source at the specified index.
	  */
	KFbxObject* GetConstraintSource(int pIndex);

	/** Set the constrainted object.
	  * \param The constrained object.
	  */
	void SetConstrainedObject(KFbxObject* pObject);

	/** Retrieve the constrainted object.
	  * \return Current constrained object.
	  */
	KFbxObject* GetConstrainedObject();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

	virtual KObject* GetFbxObject_internal();
	virtual KObject const*  GetFbxObject_internal() const;

	// Clone
	virtual KFbxObject* Clone(KFbxObject::ECloneType pCloneType) const;

protected:
	static char const* GetNamePrefix() { return CONSTRAINT_PREFIX; }

	KFbxConstraintParent(KFbxSdkManager& pManager, char const* pName);
	~KFbxConstraintParent();

	virtual void Destruct(bool pRecursive, bool pDependents);

	virtual EConstraintType GetConstraintType();
	virtual	KString	GetTypeName() const;

	// Entity manipulation
	virtual void AddChannels(KFbxTakeNode *pTakeNode);

	KFbxConstraintParent_internal* mPH;

	friend class KFbxWriterFbx6;
	friend class KFbxReaderFbx;

#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS
};

#include <fbxfilesdk_nsend.h>

#endif // _FBXSDK_CONSTRAINT_PARENT_H_

