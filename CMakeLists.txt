cmake_minimum_required(VERSION 3.20)

project(Rift
    VERSION 0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rift
    src/main.cpp
    src/lexer.cpp
)

target_include_directories(rift
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)