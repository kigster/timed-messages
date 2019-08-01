cmake_minimum_required(VERSION 3.2)
project(${PROJECT_LIBRARY} C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

set(SOURCE_FILES
        TimeSensitiveMessage.cpp
        MessageScheduler.cpp
        FrolicSchedule.cpp)

set(HEADER_FILES
        TimeSensitiveMessage.h
        MessageScheduler.h
        FrolicSchedule.h)

add_library(${PROJECT_LIBRARY} SHARED STATIC ${HEADER_FILES} ${SOURCE_FILES})

install(TARGETS ${PROJECT_LIBRARY} DESTINATION ${LIB_DIR})
install(FILES ${HEADER_FILES} DESTINATION ${INC_DIR})