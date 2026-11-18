cmake_minimum_required(VERSION 3.14)
project(observer)

aux_source_directory(. SOURCES)

add_executable(observer ${SOURCES})

target_include_directories(observer PRIVATE .)

target_compile_options(observer PRIVATE -O0 -g)