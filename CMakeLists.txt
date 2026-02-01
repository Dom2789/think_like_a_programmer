cmake_minimum_required(VERSION 3.24)
project(think_exercises)

set(SOURCE_FILES
    main.cpp
    src/chapter3.cpp)
 
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/include)