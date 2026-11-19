cmake_minimum_required(VERSION 3.14)
project(state)

aux_source_directory(. SOURCE_LIST)
add_executable(main  ${SOURCE_LIST})

target_include_directories(main PRIVATE .)
target_compile_options(main PRIVATE -O0 -g)