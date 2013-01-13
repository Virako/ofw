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
