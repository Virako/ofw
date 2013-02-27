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
find_package(Boost 1.36 REQUIRED COMPONENTS iostreams program_options regex system filesystem unit_test_framework)
IF (BOOST_FOUND)
    target_link_libraries(ofw ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
ENDIF (BOOST_FOUND)

set(SRC_test
    character_test.cpp
    ../src/character.cpp)

add_executable(character_test ${SRC_test})
target_link_libraries(character_test ${Boost_LIBRARIES})

ADD_TEST(character_test ${EXECUTABLE_OUTPUT_PATH}/character_test)
