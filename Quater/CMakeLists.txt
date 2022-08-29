cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_INCLUDE
    ./include/quater.h)
set(PROJECT_SRC
    ./src/quater.cpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)

include_directories(
    ./include
    ../Global/include)

add_library(Quater SHARED ${PROJECT_INCLUDE} ${PROJECT_SRC})

set_target_properties(Quater PROPERTIES OUTPUT_NAME "Quater")

add_compile_definitions(LIBRARY_EXPORT)