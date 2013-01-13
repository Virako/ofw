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
