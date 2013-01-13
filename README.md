ofw
===

Open Fantasy World


Requirements:
=============

* CMake, http://www.cmake.org/cmake/resources/software.html
* Irrlicht 1.8, http://downloads.sourceforge.net/irrlicht/irrlicht-1.8.zip
* Boost 1.49, http://www.boost.org/users/download/


Download:
=========

The source code is available from github, you can clone the git tree by doing:

    git clone https://github.com/Virako/ofw.git


Compilation:
============

Open Fantasy World use CMake as build system. The complete compilation process
depends on the system you are using (Linux, Mac OS X or Windows).

Quick compilation under Unix:
-----------------------------

Under Unix, assuming that Irrlicht and Boost are installed system-wide, you can
compile (with optimisation and debug information) and install Open Fantasy
World with the following commands run in the top-level directory of ofw:

    mkdir build
    cd build
    cmake ..
    make

Usage:
------

Open Fantsay World is easy to use. Just type:

    ./src/ofw

..in the build directory.

Testing:
--------

For run the test, type:

    make test

or

    ctest

..in the build directory.
