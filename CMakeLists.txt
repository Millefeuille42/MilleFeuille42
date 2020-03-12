cmake_minimum_required(VERSION 3.10)
project(42)
set(CMAKE_C_STANDARD 99)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

add_subdirectory(CMAKE/cub3D)
add_subdirectory(CMAKE/ft_printf)
add_subdirectory(CMAKE/GNL)
add_subdirectory(CMAKE/Libft)

add_executable(cub3D ${SOURCE_CUB3D})
add_executable(ft_printf ${SOURCE_PRINTF} main.c)
add_executable(get_next_line ${SOURCE_GNL} main.c)
add_executable(libft ${SOURCES_LIBFT} main.c)

set_target_properties(get_next_line PROPERTIES COMPILE_FLAGS "-D BUFFER_SIZE=12")

if (${42code})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
endif ()
if (${NHOME})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
endif ()
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

include_directories(
        /Users/mlabouri/Projekt/cub3D/minilibx/
        /usr/local/lib/
        /usr/local/include/
        /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/)
link_directories(
        /Users/mlabouri/Projekt/cub3D/minilibx/
        /usr/local/lib/
        /usr/local/include/
        /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/)
add_link_options(-framework OpenGL -framework /System/Library/Frameworks/AppKit.framework/Appkit)
target_link_libraries(cub3D LINK_PUBLIC libmlx.a)

