set(    SOURCE_CUB3D

		../../Finished/cub3D/main.c
		../../Finished/cub3D/init_conf.c

		../../Finished/cub3D/parsing/cub_parser.c
		../../Finished/cub3D/parsing/parsing_methods/parsing_methods_1.c
		../../Finished/cub3D/parsing/parsing_methods/parsing_methods_2.c
		../../Finished/cub3D/parsing/parsing_methods/parsing_methods_3.c
		../../Finished/cub3D/parsing/parsing_methods/error_check_methods.c
		../../Finished/cub3D/parsing/parsing_methods/error_check_methods_2.c
		../../Finished/cub3D/parsing/parsing_methods/sprites_init.c
		../../Finished/cub3D/parsing/GNL/get_next_line_utils.c
		../../Finished/cub3D/parsing/GNL/get_next_line.c
		../../Finished/cub3D/parsing/parsing_methods/error_check_methods_3.c

		../../Finished/cub3D/utils/ft_strdup.c
		../../Finished/cub3D/utils/ft_strjoin.c
		../../Finished/cub3D/utils/ft_strnstr.c
		../../Finished/cub3D/utils/ft_strlen.c
		../../Finished/cub3D/utils/ft_isdigit.c
		../../Finished/cub3D/utils/ft_atoi_mk2.c
		../../Finished/cub3D/utils/ft_c_in_set.c
		../../Finished/cub3D/utils/ft_substr.c
		../../Finished/cub3D/utils/ft_split.c
		../../Finished/cub3D/utils/ft_putstr_fd.c
		../../Finished/cub3D/utils/vector_matrix.c

		../../Finished/cub3D/graphical/drawing/drawing_utils.c
		../../Finished/cub3D/graphical/drawing/drawing_utils_2.c
		../../Finished/cub3D/graphical/hooks/events.c
		../../Finished/cub3D/graphical/hooks/game_loop.c
		../../Finished/cub3D/graphical/hooks/keyboard_hooks.c
		../../Finished/cub3D/graphical/hooks/keyboard_functions.c
		../../Finished/cub3D/graphical/hooks/keyboard_functions_2.c
		../../Finished/cub3D/graphical/rays/ray.c
		../../Finished/cub3D/graphical/rays/sprites_calculations.c
		../../Finished/cub3D/graphical/minimap.c
		../../Finished/cub3D/graphical/drawing/texturing.c
		../../Finished/cub3D/graphical/drawing/sprites_rendering.c
		../../Finished/cub3D/graphical/drawing/buffer_commands.c

		../../Finished/cub3D/bitmap/ft_bmp.c
		)

add_executable(cub3D ${SOURCE_CUB3D})

#add_link_options()
target_link_libraries(cub3D LINK_PUBLIC libm.so libc.so libmlx.a libX11.so libXext.so bsd.so)

set_target_properties(cub3D PROPERTIES COMPILE_FLAGS "-Ofast -L /usr/lib/ -lmlx -I /usr/include -I ./includes/")