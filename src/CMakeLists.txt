cmake_minimum_required(VERSION 3.2)
project($PROJECT)

add_subdirectory(${PROJECT_LIBRARY})

set(SOURCE_FILES main.cpp)

add_executable(scheduler ${SOURCE_FILES})
target_link_libraries(${PROJECT} ${PROJECT_LIBRARY})
install(TARGETS scheduler DESTINATION ${BIN_DIR})
install(TARGETS ${PROJECT_LIBRARY} DESTINATION ${LIB_DIR})
