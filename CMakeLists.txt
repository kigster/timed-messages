cmake_minimum_required(VERSION 3.2)
project(scheduler)

execute_process( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(INC_DIR ${PROJECT_SOURCE_DIR}/include)
set(BIN_DIR ${PROJECT_SOURCE_DIR}/bin/${ARCHITECTURE})
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib/${ARCHITECTURE})

set(PROJECT scheduler)
set(PROJECT_LIBRARY schedule)

set(EXTRA_HDRS ${PROJECT_SOURCE_DIR}/src/scheduler)

include_directories(${INC_DIR})
include_directories(${EXTRA_HDRS})

add_subdirectory(src)
add_subdirectory(spec)
