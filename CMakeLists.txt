cmake_minimum_required(VERSION 3.13)

set(YAVL_MAJOR_VERSION 0)
set(YAVL_MINOR_VERSION 1)
set(YAVL_PATCH_VERSION 0)
set(YAVL_VERSION
  ${YAVL_MAJOR_VERSION}.${YAVL_MINOR_VERSION}.${YAVL_PATCH_VERSION})

project(yavl-cpp LANGUAGES CXX VERSION "${YAVL_VERSION}")

option(yavl-cpp_BUILD_SHARED "Build the yavl-cpp::yavl-cpp library shared." OFF)

# Cmake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules")

# Check if project is subproject
get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

string(TOLOWER "${CMAKE_BUILD_TYPE}" _PROJECT_BUILD_TYPE)
set(_PROJECT_ROOT_DIR "${CMAKE_SOURCE_DIR}")
set(_PROJECT_SRC_DIR "${_PROJECT_ROOT_DIR}/src")

add_subdirectory(src/yavl-cpp)