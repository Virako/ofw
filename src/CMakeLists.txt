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

########### COMMON LIBS ###########

# Qt
find_package(Qt4 REQUIRED)

INCLUDE(${QT_USE_FILE})

SET(HWQ_Qt4_UI
    gui/select_player.ui)
SET(HWQ_Qt4_SRC
    gui/select_player.hpp
    gui/irrlicht_widget.hpp)
SET(HWQ_Qt4_RES)
SET(HWQ_LIB ${QT_LIBRARIES})

QT4_WRAP_CPP(HWQ_MOC_CPP ${HWQ_Qt4_SRC})
QT4_WRAP_UI(HWQ_UI_CPP ${HWQ_Qt4_UI})
QT4_ADD_RESOURCES(HWQ_RES_H ${HWQ_Qt4_RES})

include_directories(../build/src ../build/src/gui)


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
    SET(IRR_LIB ${IRRLICHT_LIBRARIES})
ENDIF (WIN32)
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # GL Xrand and X11 are required to compile in Linux
    SET(IRR_LIB ${IRRLICHT_LIBRARIES} GL Xrandr X11 Xxf86vm)
endif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")


SET(HWQ_SRC
    main.cpp
    character.cpp
    player.cpp
    cte.hpp
    core.cpp
    gui/select_player.cpp
    gui/irrlicht_widget.cpp
    ${HWQ_MOC_CPP}
    ${HWQ_UI_CPP}
    ${HWQ_RES_H})

ADD_EXECUTABLE (ofw ${HWQ_SRC})
TARGET_LINK_LIBRARIES(ofw ${HWQ_LIB} ${IRR_LIB})

IF(UNIX AND NOT APPLE)
    INSTALL(TARGETS ofw RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")
    INSTALL(DIRECTORY ${CMAKE_HOME_DIRECTORY}/media DESTINATION ${CMAKE_INSTALL_PREFIX}/share/ofw)
    # TODO WIN
ENDIF()
