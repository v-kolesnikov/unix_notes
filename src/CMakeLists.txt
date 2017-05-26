project(unix_notes)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_executable(2_2_env 2_2_env.c)
add_executable(2_3_env 2_3_env.c)
add_executable(2_5_sym_link 2_5_sym_link.c)
add_executable(2_6_cp 2_6_cp.c)
add_executable(2_7_file_mode 2_7_file_mode.c)
