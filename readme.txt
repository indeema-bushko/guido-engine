----------------------------------------------------------------------
Compiling the Guidolib project
----------------------------------------------------------------------

======================================================================
1) Compiling the GUIDOEngine
----------------------------------------------------------------------
The GUIDOEngine relies on CMake, a cross-platform, open-source build 
system ( see http://www.cmake.org/).
The cmake folder contains the project description and is used to generate 
native projects. 

To compile:
	change to cmake directory
	type:  cmake -G "your target generator" OPTIONS
	run your project/makefile and compile

OPTIONS indocates optional components and is between:
	-DMIDIEXPORT='yes | no' to support MIDI export
	
Note about MIDI export:
--------------------------
    MIDI export requires libmidisharelight. For MacOS and Windows, the library is embedded 
    in binary form in the src/midisharelight folder. Thus there is no additional step.
    On linux, you must get the library source code, compile and install.
	
Note for Linux platforms:
--------------------------
	The procedure to compile can be close to the usual 'configure' 'make' 'make install'
	steps. Actually, you can simply do the following:
	> cd /your_path_to_the_project/cmake
	> cmake -G "Unix Makefiles"
	> make
	> sudo make install

   Supporting MIDI export on linux:
   -------------------------------
   you must get the midishare source code:
	   git://midishare.git.sourceforge.net/gitroot/midishare/midishare 
   midisharelight is a recent addition to the project and for the moment, it is only
   available from the 'dev' branch. It is located at the project root folder.
   midisharelight is cmake based:
	> cd midisharelight/cmake
	> cmake -G "Unix Makefiles"
	> make
	> sudo make install


Note for Windows platforms:
--------------------------
	The CMake project description is "Visual Studio" oriented. 
	Using MingW may require some adaptation.


======================================================================
2) Compiling the GUIDO Qt applications
----------------------------------------------------------------------
You need to have Qt SDK version 4.6 or later installed to compile the 
GUIDO Qt applications.
(see at http://qt.nokia.com/)
You can use QTCreator on all platforms to compile the applications.
See below if you want to use another development environment.

>>>>>> Mac OS
----------------------------
To compile the GUIDO Qt applications do the following:
  > cd /your_path_to_the_guido_project/Qt
  > make projects
Next you should find Xcode projects into every application folder.
Just open the projects and compile.

>>>>>> Windows
----------------------------
To compile the GUIDO Qt applications, the easiest way is probably to use QTCreator.
However, if you want to use Visual Studio you should:
- set the QMAKESPEC variable to the corresponding output specification
  (see Qt documentation)
- generate each project in each application folder using 'qmake'
Note that a solution for Visual Studio 2005 is provided at the root of the Qt folder.
Warning, the solution works only after the individual projects have been generated.

>>>>>> Linux
----------------------------
Qt can be installed from synaptic (on Ubuntu)
To compile the GUIDO Qt applications do the following:
  > cd /your_path_to_the_guido_project/Qt
  > make unix

======================================================================
In case of trouble, contact me: <fober@grame.fr>
======================================================================
