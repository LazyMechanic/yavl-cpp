# Set debug postfix
if(NOT CMAKE_DEBUG_POSTFIX)
    set(CMAKE_DEBUG_POSTFIX "d")
endif()

# Set build type
if(yavl-cpp_BUILD_SHARED)
  set(yavl-cpp_LIBRARY_TYPE "SHARED")
else()
  set(yavl-cpp_LIBRARY_TYPE "STATIC")
endif()

# Build type in lower case
string(TOLOWER "${yavl-cpp_LIBRARY_TYPE}" yavl-cpp_LIBRARY_TYPE_LOWER)

# Get lib sources
file(
    GLOB yavl-cpp_SRC
    "*.h"
    "*.hpp"
    "*.cc"
    "*.cpp")

# Create lib target
add_library(yavl-cpp ${yavl-cpp_LIBRARY_TYPE} "${yavl-cpp_SRC}")
add_library(yavl-cpp::yavl-cpp ALIAS yavl-cpp)

# Enable C++17 on this project
target_compile_features(yavl-cpp INTERFACE cxx_std_17)

# Set specific properties
set_target_properties(
    yavl-cpp PROPERTIES
    OUTPUT_NAME "yavl-cpp"
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

# Set include directories for this project and if it will use as installing
target_include_directories(
    yavl-cpp INTERFACE
    $<BUILD_INTERFACE:${_PROJECT_SRC_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/yavl-cpp>)

# Find Protobuf
find_package(yaml-cpp CONFIG REQUIRED)

# Set Protobuf dependency
target_link_libraries(
    yavl-cpp 
    yaml-cpp)

# Installing headers
file(
    GLOB yavl-cpp_HEADERS
    "*.h"
    "*.hpp")
 
# Install headers
install(
    FILES ${yavl-cpp_HEADERS}
    DESTINATION "include/yavl-cpp")
    
# Install building files and create export target
install(
    TARGETS yavl-cpp
    EXPORT yavl-cpp_export
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)

# Generate config
include(CMakeBuildHelper/BuildHelper)
generate_config(
    # Pass export targets for install config targets file
    EXPORT_TARGETS yavl-cpp_export
    # Set namespace for targets
    NAMESPACE yavl-cpp::
    # Set config file which need to use
    IN_CONFIG_FILE "${_PROJECT_ROOT_DIR}/cmake/yavl-cpp-config.cmake.in"
    # Set path prefix where config files will generate. In this case it is "${PROJECT_BINARY_DIR}/yavl-cpp-config.cmake" and etc. 
    OUT_PATH_PREFIX "${PROJECT_BINARY_DIR}"
    # Set name prefix for all config files
    OUT_NAME_PREFIX "yavl-cpp"
    # Arg need to generate several targets file, for example for static and shared libs (optional).
    # In this case it is "${OUT_NAME_PREFIX}${OUT_TARGETS_FILE_SUFFIX}-targets.cmake" (in HYPHEN_CASE)
    OUT_TARGETS_FILE_SUFFIX "-${yavl-cpp_LIBRARY_TYPE_LOWER}"
    # Version of package
    VERSION "${PROJECT_VERSION}"
    # Compatibility package by version
    COMPATIBILITY AnyNewerVersion
    # Params which pass to "*config.cmake.in" file
    # syntax:
    # CONFIG_PARAMS
    #        "<KEY>=<VALUE>"
    #        "<KEY>=<VALUE>"
    #        "<KEY>=<VALUE>"
    CONFIG_PARAMS
        "TARGETS_CONFIG_FILE=yavl-cpp-${yavl-cpp_LIBRARY_TYPE_LOWER}-targets.cmake"
    # When set HYPHEN_CASE then config file whill ganerate in this style: *-config.cmake, *-config-version.cmake, etc.
    # When set CAMEL_CASE then config file whill ganerate in this style: *Config.cmake, *ConfigVersion.cmake, etc.
    HYPHEN_CASE)