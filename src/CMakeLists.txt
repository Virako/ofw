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

set(SRC_files
    main.cpp
    character.cpp
    player.cpp
    cte.hpp)

# ADD THE EXECUTABLE
ADD_EXECUTABLE (ofw ${SRC_files})

########### COMMON LIBS ###########

# Irrlicht
find_package(Irrlicht REQUIRED)
if (${IRRLICHT_VERSION} MATCHES "1.8")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DIRRLICHT_VERSION=18")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DIRRLICHT_VERSION=18")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DIRRLICHT_VERSION=18")
endif (${IRRLICHT_VERSION} MATCHES "1.8")

include_directories(${IRRLICHT_INCLUDE_DIRS})
IF (WIN32)
    # TODO: check
    target_link_libraries (ofw ${IRRLICHT_LIBRARIES})
ENDIF (WIN32)
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # GL Xrand and X11 are required to compile in Linux
    target_link_libraries (ofw ${IRRLICHT_LIBRARIES} GL Xrandr X11 Xxf86vm)
endif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")

# Project executable output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)
