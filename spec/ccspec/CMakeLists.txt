cmake_minimum_required(VERSION 2.8.11)

if(BIICODE)
  include("biicode.cmake")
  return()
endif()

if(APPLE)
  set(CMAKE_MACOSX_RPATH ON)
endif()

INCLUDE (CMakeForceCompiler)
CMAKE_FORCE_C_COMPILER(clang Clang)
CMAKE_FORCE_CXX_COMPILER(clang++ Clang)

# you can set llvm_lib_dir if the default clang is not working.
#set(LLVM_LIB_DIR  /usr/lib/llvm-5.0)
#include_directories(BEFORE "${LLVM_LIB_DIR}/lib/clang/5.0.2/include")
#include_directories(BEFORE "${LLVM_LIB_DIR}/include")

project(ccspec)
add_subdirectory(src)
add_subdirectory(spec)
enable_testing()
add_test(NAME ccspec_spec COMMAND ccspec_spec)
