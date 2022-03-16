cmake_minimum_required(VERSION 3.21)
project(fdf C)

set(CMAKE_C_STANDARD 23)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

include_directories(src)

link_directories(ftprintf .)

add_executable(fdf src/utils.c
        src/draw.c
        src/utils_2.c
        src/get_next_line.c
        src/get_next_line_utils.c
        src/main.c
        src/parcer.c)

target_link_libraries(fdf ftprintf mlx Xext X11 m)