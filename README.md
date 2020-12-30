![barbielogo]
###	Suicide Barbie by The Black Lotus   
####      A PlayStation® Portable™ demo

####	Release History

* [Source code](https://github.com/theblacklotus/suicide-barbie) (MIT licensed) released December 31st, 2020.
* OE/M33 'slim' version released on July 8th, 2008.
* 'Polished' party version released on June 27th, 2007.
* Original production released at [Breakpoint 2007](https://breakpoint.untergrund.net/2007/).
 
####    Awards & Nominations
* 1st place [Console / Real Wild](https://breakpoint.untergrund.net/2007/compos_misc.php) demo competition at [Breakpoint 2007](https://breakpoint.untergrund.net/2007/).
* [Public Choice](https://www.pouet.net/awards.php#2007public-choice) nominee at [Scene.org 6th Annual Demoscene Awards](http://awards.scene.org/).
 
  :trumpet:  [pouët.net](https://www.pouet.net/prod.php?which=30284)  
  :movie_camera:  [YouTube](https://www.youtube.com/watch?v=Q1J7EBzwN3Q)

---

###	How Suicide Barbie Came To Be

After the success of the Starstruck demo, TBL needed a new challenge. It had to be a demo on a new platform. On a well defined and fixed platform, but with hardware powerful enough. Platform unhindered by layers of software abstractions one finds in PC. Limited, yet modern. Inspired by Playstation® 2 demo [4 Edges](https://www.pouet.net/prod.php?which=24552) and hacker spirit of the Homebrew community we soon had a winner - a miniaturized beast of Playstation® with a vibrant screen. A harbinger of the new future where great visuals fit in your pocket - PlayStation® Portable™!

The goal was simple: make the most Entertaining Visual Experience, the Best Demo for the platform! And although the author is clearly biased here, but it looks like Suicide Barbie holds its ground even today and still is the best demo on the PlayStation® Portable™.

#### PlayStation® Portable™ Specs
Original PlayStation® Portable™ SoC is built on a 90nm CMOS process and is powered by 1.2V.

    ~ 32-bit [MIPS R4000](https://en.wikipedia.org/wiki/R4000) CPU clocked @ 222 MHz.  
    ~ VFPU compute co-processor pushing 2.6 GigaFlops.  
    ~ [Graphics Core](https://www.techpowerup.com/gpu-specs/sony-psp-1000-gpu.b8184) triangle rasterizer with fixed T&L pipeline that can spit up to 33M triangles and cover 665M pixels per second.  
    ~ 32 MiB main RAM.  
    ~ 2 MiB Graphics eDRAM.  

![psp]

---

####	Credits

        Direction, Graphics:   Louie / TBL^CNCD  
        Graphics:                    Jintz  
  
        Code:                          ReJ / Nesnausk!  
        Code:                          eriQue / soniK cliQue  
  
        Music:                         Elusive _'Pete loves Veronica mix'_  
                                               (Veronica Maggio ['Dumpa Mig'](https://www.youtube.com/watch?v=fphQeXPvTaI))

        Animations:                Micke   
        Animations:                Johra   
        Animations:                Duffe   

        Additional Graphics:  Eracore / Rebels

        Platform Consultant: Chip
 
####	Additional Credits & Inspiration

        Roberto Roseano (Barbie Suicide)  
        Psyop
 
####	Special Thanks

        [pspdev](https://github.com/pspdev) community for homebrew  
        TyRaNiD for [psplink](https://github.com/pspdev/psplinkusb) (this demo would not've been possible without it)  
        orlok^simple / Nesnausk! for mutant lib  
        daywish^cathy / Nesnausk! for support and photojournalism in Bingen  

---

###	How To Run The Production on PlayStation® Portable™ device

This production has been tested and confirmed working under firmware 1.00, 1.50 and 3.40 OE-A (150 binary) and 3.90 M33-3 and 4.01 M33-2 (OE/M33/Slim binary). Use a fast memory stick like SanDisk 2GB to guarantee a smooth viewing experience.

    ~ Unpack the contents of the archive from the [releases](../../releases) to the `ms0:/PSP/GAME/` folder on your [Memory Stick](https://en.wikipedia.org/wiki/Memory_Stick).  
    ~ If you're using Open Edition [OE/M33](https://playstationdev.wiki/pspdevwiki/index.php?title=M33_Firmware) firmware, and the original 150 binaries, copy the files to `ms0:/PSP/GAME150/` instead.  
    ~ Run the production from the XMB (Playstation Portable menu screen) as you would do with a regular game.  

####	How To Run The Production in Emulator

If you do not own a PlayStation® Portable™ device, we recommend installing the [`ppsspp`](https://www.ppsspp.org/) emulator.  
PPSSPP even lists **Suicide Barbie** within its *PPSSPP Homebrew Store*, making it easy to enjoy the production.

---
###	How To Build and Run From Source

_This has only been tested with macOS 10.14+ (using [brew](https://brew.sh/)) and Ubuntu 20.04 LTS (Focal Fossa)_

macOS  : `brew install autoconf automake flex gcc@9 ncurses make subversion texinfo wget ppsspp`\
Ubuntu : `apt install autoconf automake bison flex gcc-9 libncurses-dev make subversion texinfo wget`

1. Bootstrap the environment using a 2006'ish snapshot of the homebrew PSP toolchain and SDK via  

	`./bootstrap.sh`

0. Build the source via

	`./build.sh`

0. Either use [psplinkusb](https://github.com/pspdev/psplinkusb), and run it via `usbhostfs_pc` using

	`./psplink.sh`  
\
or, run it emulated (assuming [`ppsspp`](https://www.ppsspp.org/) is installed) using

	`./emulate.sh`


---
####	License

The source code found in this repository is licensed under the [MIT license](LICENSE) (*except where other licenses apply*).  
The source assets (*textures, meshes, etc, found under [Data](Data)*) are Copyright © 2020 and licensed under a [CC BY-SA 4.0 license](https://creativecommons.org/licenses/by-sa/4.0/).

---

### Core Crew
![corecrew]

### Bingen, Germany, a few hours before the deadline
![coding]

[barbielogo]: www/barbielogo.png  "Suicide Barbie"
[psp]: www/OnDevice.jpg "Suicide Barbie on PSP1000"
[corecrew]: www/CoreCrew.jpg  "eriQue | Louie500 | ReJ"
[coding]: www/Coding.jpg "Coding in Bingen 2007"
