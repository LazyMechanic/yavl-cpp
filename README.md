# Description
This is fork of yaml-cpp validator with cmake and new API support

# Dependencies
To build this project you need:
- [yaml-cpp](https://github.com/jbeder/yaml-cpp)
- [CMakeBuildHelper](https://github.com/LazyMechanic/CMakeBuildHelper) (download like submodule)

# Getting sources
Download from github:
```bash
$ git clone https://github.com/LazyMechanic/yavl-cpp --recursive
```

# CMake configuration
Create a temporary `build` folder and change your working directory to it:
```bash
$ mkdir build
$ cd build/
```

Make `yavl-cpp`:
```bash
$ cmake                                \
    -DCMAKE_BUILD_TYPE=[Debug|Release] \ 
    -G "MinGW Makefiles"               \
    ..
```

For build by `MSVC` you need use Visual Studio Prompt:
```bash
$ cmake                                \
    -DCMAKE_BUILD_TYPE=[Debug|Release] \ 
    -G "NMake Makefiles"               \
    ..
```

# CMake options
If `yaml-cpp` installed into specific directory then set:
```bash
-Dyaml-cpp_DIR=<root_dir_yaml-cpp>/cmake
```

Generate specific project, for example `Visual Studio solution` generator:
```bash
-G "Visual Studio 16"
```

Set specific compiler, for example `Clang`:
```bash
-DCMAKE_CXX_COMPILER=clang++
```

Build like shared library (static by default):
```bash
-Dyavl-cpp_BUILD_SHARED=ON
```

# Compiling
To compile `yavl-cpp`:
```bash
$ cmake --build .
```

# Installing
To install `yavl-cpp` to the specified install folder
```bash
$ cmake --install . --prefix=/path/to/install
```

# How to use
Check [example](https://github.com/LazyMechanic/yavl-cpp/tree/master/example) folder