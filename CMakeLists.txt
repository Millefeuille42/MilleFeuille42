cmake_minimum_required(VERSION 3.10)
project(42)
set(CMAKE_CXX_STANDARD 99)

add_subdirectory(CMAKE/cub3D)
add_subdirectory(CMAKE/ft_printf)
add_subdirectory(CMAKE/GNL)
add_subdirectory(CMAKE/Libft)

add_executable(cub3D ${SOURCE_CUB3D} cub3D/parsing/parsing_methods/parsing_methods_1.c cub3D/utils/ft_isdigit.c cub3D/utils/ft_atoi_mk2.c cub3D/utils/ft_c_in_set.c cub3D/parsing/parsing_methods/error_check_methods.c cub3D/parsing/parsing_methods/parsing_methods_3.c)
add_executable(ft_printf ${SOURCE_PRINTF} main.c)
add_executable(get_next_line ${SOURCE_GNL} main.c)
add_executable(libft ${SOURCES_LIBFT} main.c)

set_target_properties(get_next_line PROPERTIES COMPILE_FLAGS "-D BUFFER_SIZE=12")

if (${42code})
    #set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
endif ()
if (${NHOME})
  #  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
endif ()
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")