set(SRC_files
    main.cpp
    character.cpp
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
    target_link_libraries (ofw ${IRRLICHT_LIBRARIES} GL Xrandr X11)
endif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")

# Project executable output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)
