# Copyright (c) <2014-2017> <Newton Game Dynamics>
#
# This software is provided 'as-is', without any express or implied
# warranty. In no event will the authors be held liable for any damages
# arising from the use of this software.
#
# Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely.

cmake_minimum_required(VERSION 3.4.0)

set (projectName "ndSandbox")
message (${projectName})

# source and header files
file(GLOB CPP_SOURCE 
	*.h
	*.cpp
	demos/*.h
	demos/*.cpp
	toolBox/*.h
	toolBox/*.cpp 
)

#source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/" PREFIX source/ FILES ${CPP_SOURCE})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/" FILES ${CPP_SOURCE})

include_directories(./)
include_directories(toolbox/)
include_directories(../../sdk/dCore/)
include_directories(../../sdk/dNewton/)
include_directories(../../sdk/dTinyxml/)
include_directories(../../sdk/dCollision/)
include_directories(../../sdk/dNewton/dModels)
include_directories(../../sdk/dNewton/dJoints)
include_directories(../../thirdParty/glfw/)
include_directories(../../thirdParty/imgui/)
include_directories(../../thirdParty/openFBX/src/)
include_directories(../../thirdParty/glfw/include/)
include_directories(../../thirdParty/glatter/include/glatter/)

add_executable(${projectName} ${CPP_SOURCE})

if (NEWTON_BUILD_CREATE_SUB_PROJECTS)
	target_link_libraries (${projectName} ndNewton ndCollision ndCore glfw imgui glatter openfbx)
else()
	target_link_libraries (${projectName} ndNewton glfw imgui glatter openfbx)
endif()

if (NEWTON_BUILD_PROFILER)
	target_link_libraries (${projectName} dProfiler)
endif ()

if(MSVC OR MINGW)
    target_link_libraries (${projectName} glu32 opengl32)

    if(CMAKE_VS_MSBUILD_COMMAND OR CMAKE_VS_DEVENV_COMMAND)
		set_target_properties(${projectName} PROPERTIES COMPILE_FLAGS "/YundSandboxStdafx.h")
		set_source_files_properties(ndSandboxStdafx.cpp PROPERTIES COMPILE_FLAGS "/YcndSandboxStdafx.h")
		set_source_files_properties(toolBox/ndFileBrowser.cpp PROPERTIES COMPILE_FLAGS "/Y-")
    endif()
endif()

if(UNIX)
    target_link_libraries (${projectName} GL GLU dl X11 pthread)
    set (source "${CMAKE_SOURCE_DIR}/applications/media")
    set (destination "${PROJECT_BINARY_DIR}/applications/media")
    add_custom_command(
        TARGET ${projectName} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
        DEPENDS ${destination}
        COMMENT "symbolic link resources folder from ${source} => ${destination}")
endif()

if(WIN32)
    file(COPY ../media DESTINATION "${PROJECT_BINARY_DIR}/applications")
endif()

install(DIRECTORY ../media DESTINATION "${PROJECT_BINARY_DIR}/applications")

