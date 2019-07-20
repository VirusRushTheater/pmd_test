# PMD Engine Coded in C #
This is simply a PMD clone engine coded in C. Originally it was made as a Windows/MSVC project, however, given the fact most of the project uses portable libraries, I decided to work on a Linux/GCC port. This, instead of relying on the Microsoft Visual Studio platform to build it, it's deployed as a CMake project.

It is a project in development, so many compiling and runtime errors may appear.

## Compiling ##
You need to install a compiler of your choice that supports C++11 and CMake; and install the following libraries plus C include files:
* OpenGL
* OpenAL
* GLEW
* GLFW
* SDL2

Then, to compile it, you may follow the standard CMake build procedure: make a `build` directory, run `cmake ..` and then `make` on it. If no errors, the executable should be in that folder.

You can assist yourself with an IDE with CMake support such as VSCodium (with the proper extensions), QT Creator or Microsoft Visual Studio to assist and debug the program.

## Changes in comparison to the original Purpasmart repository ##
* Removed the Visual Studio project files and used CMake instead.
* Added a LICENSE file, in according to the license that appears on all source files.
* Removed the built dynamic library folder `lib`. In its place, the folder `third-party` was made. There, sources from obscure libraries are included in the Build recipe for the PMD Engine.
* Edited the necessary source files for them to use Posix Threads (pthread) and Windows Threads depending on the platform it's compiled on.
* Adapted the Fast Sqrt method for it to use GCC Extended Assembly on non-MSVC build systems.
* Include pointer casting in all memory allocation methods (malloc and realloc).
* Minor modification in functions so conflicts with pointer-integer assignment don't give warnings.

## Projected changes ##
* Naturally, to work on Linux/GCC (and Windows/MinGW if possible).
* Add an automated data package-making script
* Un-hardcode some settings.