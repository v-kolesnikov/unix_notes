cmake_minimum_required(VERSION 3.2)

project(unix_notes_root)

enable_testing()

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)
