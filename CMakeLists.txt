cmake_minimum_required(VERSION 3.10)
project(42)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

include_directories(
        /usr/include
        /usr/local/include
)
link_directories(
        /usr/include
        /usr/local/include
)

add_subdirectory(CMAKE/Libft)
add_subdirectory(CMAKE/GNL)
add_subdirectory(CMAKE/ft_printf)
add_subdirectory(CMAKE/cub3D)
add_subdirectory(CMAKE/minishell)

add_executable(libft ${SOURCES_LIBFT} main.c)

add_executable(get_next_line ${SOURCE_GNL} main.c)
add_executable(ft_printf ${SOURCE_PRINTF} main.c)

add_executable(cub3D ${SOURCE_CUB3D})

add_executable(minishell ${SOURCE_MINISHELL}Minishell/main.c )# Minishell/libftstring/ft_parse.c Minishell/libftstring/ft_clear.c Minishell/libftstring/ft_append.c)

set_target_properties(get_next_line PROPERTIES COMPILE_FLAGS "-D BUFFER_SIZE=12")

if (${WFLAGS})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -std=c99 -pedantic-errors")
endif ()
if (${SAN})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
endif ()
if (${COVER})
    set(CMAKE_C_COMPILER /usr/bin/gcc)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
endif ()
if (${OPTI})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast")
endif ()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

target_link_libraries(cub3D LINK_PUBLIC libm.so libc.so libmlx.a libX11.so libXext.so bsd.so)
add_link_options(-framework OpenGL -framework /System/Library/Frameworks/AppKit.framework/Appkit)
