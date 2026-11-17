cmake_minimum_required(VERSION 3.14)
project(mediator)

aux_source_directory(. SRC_LIST)
add_executable(main ${SRC_LIST})

target_include_directories(main PRIVATE .)
target_compile_options(main PRIVATE -O0 -g)