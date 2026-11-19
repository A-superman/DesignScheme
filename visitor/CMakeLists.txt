cmake_minimum_required(VERSION 3.14)
project(visitor)

aux_source_directory(. SOURCE_LIST)
add_executable(main ${SOURCE_LIST})

target_compile_options(main PRIVATE -O0 -g)
target_include_directories(main PRIVATE .)