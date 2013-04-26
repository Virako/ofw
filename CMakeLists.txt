# Open Fantasy World is a MMORPG where the players will live in community.
# Copyright (C) 2012-2013 Víctor Ramirez de la Corte <virako.9@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Foobar is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

project(ofw)

# set minimum version
cmake_minimum_required(VERSION 2.6)

# Compile with g++
IF(CMAKE_COMPILER_IS_GNUCXX)
    MESSAGE(STATUS "G++ detected - Adding compiler flags")
    # TARGETS. # Add -Wextra warning: unused parameter in irrlicht. ↓
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -std=c++0x -pedantic -ggdb $ENV{CXXFLAGS}")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -Wextra -fno-inline $ENV{CXXFLAGS}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O2 $ENV{CXXFLAGS}")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

# Use the own version of FindXXX.cmake scripts
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)


#Path options
set(BINDIR "bin" CACHE STRING "Where to install binaries")
set(DATAROOTDIR "${CMAKE_INSTALL_PREFIX}/share" CACHE STRING "Sets the root of data directories to a non-default location")
set(DATADIRNAME "ofw")
set(DATADIR ${DATAROOTDIR}/${DATADIRNAME})
set(LOCALEDIR "locale")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)

add_definitions(-DOFW_PATH="${DATADIR}")
add_definitions(-DLOCALEDIR="${LOCALEDIR}")
add_definitions(-DDATADIR="${DATADIR}")

#-- Add an Option to toggle the generation of the API documentation
option(BUILD_DOCUMENTATION "Use Doxygen to create the HTML based API documentation" OFF)
if(BUILD_DOCUMENTATION)
  FIND_PACKAGE(Doxygen)
  if (NOT DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen is needed to build the documentation. Please install it correctly")
  endif()
  #-- Configure the Template Doxyfile for our specific project
  configure_file(ofw.in ${PROJECT_BINARY_DIR}/Doxyfile  @ONLY IMMEDIATE)
  #-- Add a custom target to run Doxygen when ever the project is built
  add_custom_target (Docs
                    COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile
                    SOURCES ${PROJECT_BINARY_DIR}/Doxyfile)
  # IF you do NOT want the documentation to be generated EVERY time you build the project
  # then leave out the 'ALL' keyword from the above command.
endif()

# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)


# CPack
SET(CPACK_GENERATOR "DEB;RPM") # TODO NSIS for WIN
#SET(CPACK_PACKAGE_NAME "OpenFantasyWorld")
SET(CPACK_PACKAGE_VERSION_MAJOR "1")
SET(CPACK_PACKAGE_VERSION_MINOR "0")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Open Fantasy Wordl is a MMORPG where the players will live in community.")
SET(CPACK_PACKAGE_VENDOR "Victor Ramirez de la Corte")
SET(CPACK_PACKAGE_CONTACT "Victor Ramirez virako.9@gmail.com")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_HOME_DIRECTORY}/README.md")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_HOME_DIRECTORY}/COPYING")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CPack ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
#SET(CPACK_PACKAGE_EXECUTABLES "ofw";"Open Fantasy Wordl is a MMORPG where the player will live in community. ")

IF(UNIX)
    #DEB
    SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Victor Ramirez")
    SET(CPACK_DEBIAN_PACKAGE_DEPENDS "g++ (>= 4.6), cmake (>= 2.8), libirrlicht-dev (>= 1.7)")
    SET(CPACK_DEBIAN_PACKAGE_SECTION "games")
    #SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE i386)
    #SET(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
    #SET(CPACK_DEBIAN_PACKAGE_SUGGESTS "cmatrix (>= 1.0), sl (>= 3.0)")

    #RPM
    SET(CPACK_RPM_PACKAGE_REQUIRES "gcc-c++ >= 4.6, cmake >= 2.8, irrlicht-devel >= 1.7")
ENDIF(UNIX)

Include(CPack)


ENABLE_TESTING()
add_subdirectory(src)
add_subdirectory(tests)

INSTALL(DIRECTORY media locale DESTINATION ${DATADIR})
