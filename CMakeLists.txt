cmake_minimum_required(VERSION 3.10)
project(42)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

#if (${WFLAGS})
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -std=c99 -pedantic-errors")
#endif (${WFLAGS})
#
#if (${SAN})
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
#endif (${SAN})
#
#if (${COVER})
#    set(CMAKE_C_COMPILER /usr/bin/gcc)
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
#endif (${COVER})
#
#if (${OPTI})
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast")
#endif (${OPTI})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

#add_subdirectory(CMAKE/Libft)
#add_subdirectory(CMAKE/GNL)
#add_subdirectory(CMAKE/ft_printf)
#add_subdirectory(CMAKE/cub3D)
#add_subdirectory(CMAKE/minishell)

add_subdirectory(CMAKE/philosophers)