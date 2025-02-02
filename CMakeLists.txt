cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

# Metadata
project(LogiSceneGraph VERSION 0.1.0 LANGUAGES CXX)

# Add path to CMake custom modules.
list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")

# C++ Google Test
option(BUILD_TESTS "Build tests." ON)
option(BUILD_DOC "Build documentation" OFF)

##############################################
# BUILD LOGI LIBRARY
############################################## 

# Libraries path
include(ExternalDependencies.cmake)

file(GLOB_RECURSE SRC_LIST "src/*.cpp")

add_library(LogiSceneGraph STATIC ${SRC_LIST})

target_include_directories(LogiSceneGraph PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libs/tinygltf>
        $<INSTALL_INTERFACE:include>
        )

target_include_directories(LogiSceneGraph PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

target_link_libraries(LogiSceneGraph GLM::glm Vulkan::Vulkan)

##########################################################
####################### DOXYGEN ##########################
##########################################################

if (BUILD_DOC)
    # Check if Doxygen is installed
    find_package(Doxygen)

    if (DOXYGEN_FOUND)
        # Set input and output files
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

        # Request to configure the file
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
        message("Doxygen build started")

        # Note the option ALL which allows to build the docs together with the application
        add_custom_target(doc_doxygen ALL
                COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
                COMMENT "Generating API documentation with Doxygen"
                VERBATIM)
    else (DOXYGEN_FOUND)
        message("Doxygen need to be installed to generate the doxygen documentation")
    endif (DOXYGEN_FOUND)
endif (BUILD_DOC)

##############################################
# TESTS
##############################################

if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif (BUILD_TESTS)