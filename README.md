# Open Fantasy World [![Travis](https://secure.travis-ci.org/Virako/ofw.png)](http://travis-ci.org/Virako/ofw)

Open Fantasy World is a MMORPG where the players will live in community.


## Requirements:

* CMake, http://www.cmake.org/cmake/resources/software.html
* Irrlicht 1.8, http://downloads.sourceforge.net/irrlicht/irrlicht-1.8.zip
* Boost 1.49, http://www.boost.org/users/download/
* Doxygen 1.8, http://www.stack.nl/~dimitri/doxygen/download.html
* Qt 4.8, http://qt-project.org/downloads

For install this requirements in Debian or distributions based on Debian, type:

    sudo apt-get install cmake libirrlicht-dev libboost-all-dev doxygen libqt4-dev libqtcore4 libxxf86vm-dev


## Download:

The source code is available from github, you can clone the git tree by doing:

    git clone https://github.com/Virako/ofw.git


## Compilation:

Open Fantasy World use CMake as build system. The complete compilation process
depends on the system you are using (Linux, Mac OS X or Windows).

### Quick compilation under Unix:

Under Unix, assuming that Irrlicht and Boost are installed system-wide, you can
compile (with optimisation and debug information) and install Open Fantasy
World with the following commands run in the top-level directory of ofw:

    mkdir build
    cd build
    cmake ..
    make

### Generate documentation

For you generate documentation, type:

    cmake -DBUILD_DOCUMENTATION=ON ..
    make Docs

### Generate package DEB and RPM

For you generate package DEB and RPM, you need execute:

    make package

### Usage:

Open Fantsay World is easy to use, the executable is in the bin folder. Just
type:

    ./ofw

..in the bin directory.

### Testing:

For run the test, type:

    make test

or

    ctest

..in the build directory.

## FAQ

__Error__: I get error when I run ofw:

    pure virtual method called
    terminate called without an active exception
    Aborted (core dumped)

__Solve__: You need install irrlicht version 1.8. This problem happens in kernel 3.8.5

__Error__: If I install the generate package(DEB or RPM), When I execute ofw, I get error: "Could
not load mesh, because file could not be opened: : ../media/ninja.b3d"

__Solve__: You can execute the program in the directory CMAKE\_PREFIX/media. This feature will be
performance in the future ;)

## License

Open Fantasy World is licensed under GPL v3.
[![GPL v3](http://www.gnu.org/graphics/gplv3-127x51.png)](http://www.gnu.org/licenses/gpl.html)
