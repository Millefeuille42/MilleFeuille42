cmake_minimum_required(VERSION 3.10)
project(42)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER /usr/bin/gcc)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
#add_subdirectory(CMAKE/Libft)
#add_subdirectory(CMAKE/GNL)
#add_subdirectory(CMAKE/ft_printf)
#add_subdirectory(CMAKE/cub3D)
#add_subdirectory(CMAKE/minishell)

#add_subdirectory(CMAKE/philosophers)
add_subdirectory(CMAKE/push_swap)