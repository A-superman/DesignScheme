cmake_minimum_required(VERSION 3.14)

project(iterater)

aux_source_directory(. SOURCES)

add_executable(main ${SOURCES})

target_include_directories(main PRIVATE "include")

target_compile_options(main PRIVATE -O0 -g)