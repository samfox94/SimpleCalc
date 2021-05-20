cmake_minimum_required(VERSION 3.20.2)

project(simplecalc VERSION 1.0.0)

add_library(
    simplecalc_lib
        hdrs/simplecalc.h
        src/simplecalc.c
)

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE simplecalc_lib)

