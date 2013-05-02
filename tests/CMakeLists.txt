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

include_directories(../src)

# Boost
find_package(Boost 1.36 REQUIRED COMPONENTS unit_test_framework)
IF (BOOST_FOUND)
    target_link_libraries(ofw ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY}
            ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
ENDIF (BOOST_FOUND)

# Irrlicht
find_package(Irrlicht REQUIRED)
if (${IRRLICHT_VERSION} MATCHES "1.8")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DIRRLICHT_VERSION=18")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DIRRLICHT_VERSION=18")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DIRRLICHT_VERSION=18")
elseif (${IRRLICHT_VERSION} MATCHES "1.7")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DIRRLICHT_VERSION=17")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DIRRLICHT_VERSION=17")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DIRRLICHT_VERSION=17")
endif ()

include_directories(${IRRLICHT_INCLUDE_DIRS})
IF (WIN32)
    # TODO: check
    SET(IRR_LIB ${IRRLICHT_LIBRARIES})
ENDIF (WIN32)
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # GL Xrand and X11 are required to compile in Linux
    SET(IRR_LIB ${IRRLICHT_LIBRARIES} GL Xrandr X11 Xxf86vm)
endif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")


set(SRC_test_player
    player_test.cpp
    ../src/character.cpp
    ../src/player.cpp
    ../src/picacode.cpp
    ../src/hacker.cpp
    ../src/cracker.cpp
    ../src/designer.cpp
    ../src/hunterbug.cpp)

add_executable(player_test ${SRC_test_player})

target_link_libraries(player_test ${Boost_LIBRARIES} ${IRR_LIB})

ADD_TEST(player_test ${EXECUTABLE_OUTPUT_PATH}/player_test)
