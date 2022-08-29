cmake_minimum_required(VERSION 3.5)

project(ComputeGraphicProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
   ./ComputeGraphic/src/main.cpp
    )

add_subdirectory(Quater)

set(PROJECT_LIBS
    ./lib/Debug/Quater)

include_directories(    
    ${PROJECT_SOURCE_DIR}/Quater/include
    ${PROJECT_SOURCE_DIR}/Global/include
    ${PROJECT_SOURCE_DIR}/ComputeGraphic/include
    )

add_executable(ComputeGraphicProject 
    ${PROJECT_SOURCES}
    )

target_link_libraries(ComputeGraphicProject PRIVATE
    ${PROJECT_LIBS}
    )