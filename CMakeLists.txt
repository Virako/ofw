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
    SET(CMAKE_CXX_FLAGS "-std=c++03 -pedantic -pthread -ggdb")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O2")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

# Use the own version of FindXXX.cmake scripts
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

ENABLE_TESTING()
add_subdirectory(src)
add_subdirectory(tests)
