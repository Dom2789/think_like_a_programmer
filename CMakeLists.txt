cmake_minimum_required(VERSION 3.24)
project(think_exercises)

set(SOURCE_FILES
    main.cpp
    src/chapter3.cpp
    src/chapter4.cpp
    src/chapter5.cpp
    src/chapter6.cpp
    src/chapter7.cpp
    src/chapter8.cpp)
 
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/include)