set(    SOURCE_CUB3D

		../../In_Progress/cub3D/main.c
		../../In_Progress/cub3D/init_conf.c

		../../In_Progress/cub3D/parsing/cub_parser.c
		../../In_Progress/cub3D/parsing/parsing_methods/parsing_methods_1.c
		../../In_Progress/cub3D/parsing/parsing_methods/parsing_methods_2.c
		../../In_Progress/cub3D/parsing/parsing_methods/parsing_methods_3.c
		../../In_Progress/cub3D/parsing/parsing_methods/error_check_methods.c
		../../In_Progress/cub3D/parsing/parsing_methods/error_check_methods_2.c
		../../In_Progress/cub3D/parsing/parsing_methods/sprites_init.c
		../../In_Progress/cub3D/parsing/GNL/get_next_line_utils.c
		../../In_Progress/cub3D/parsing/GNL/get_next_line.c
		../../In_Progress/cub3D/parsing/parsing_methods/error_check_methods_3.c

		../../In_Progress/cub3D/utils/ft_strdup.c
		../../In_Progress/cub3D/utils/ft_strjoin.c
		../../In_Progress/cub3D/utils/ft_strnstr.c
		../../In_Progress/cub3D/utils/ft_strlen.c
		../../In_Progress/cub3D/utils/ft_isdigit.c
		../../In_Progress/cub3D/utils/ft_atoi_mk2.c
		../../In_Progress/cub3D/utils/ft_c_in_set.c
		../../In_Progress/cub3D/utils/ft_substr.c
		../../In_Progress/cub3D/utils/ft_split.c
		../../In_Progress/cub3D/utils/ft_putstr_fd.c
		../../In_Progress/cub3D/utils/vector_matrix.c

		../../In_Progress/cub3D/graphical/drawing/drawing_utils.c
		../../In_Progress/cub3D/graphical/drawing/drawing_utils_2.c
		../../In_Progress/cub3D/graphical/hooks/events.c
		../../In_Progress/cub3D/graphical/hooks/keyboard_hooks.c
		../../In_Progress/cub3D/graphical/hooks/keyboard_functions.c
		../../In_Progress/cub3D/graphical/hooks/keyboard_functions_2.c
		../../In_Progress/cub3D/graphical/rays/ray.c
		../../In_Progress/cub3D/graphical/rays/sprites_calculations.c
		../../In_Progress/cub3D/graphical/minimap.c
		../../In_Progress/cub3D/graphical/drawing/texturing.c
		../../In_Progress/cub3D/graphical/drawing/sprites_rendering.c
		../../In_Progress/cub3D/graphical/drawing/buffer_commands.c

		../../In_Progress/cub3D/bitmap/ft_bmp.c

		)

add_executable(cub3D ${SOURCE_CUB3D})

add_link_options(-framework OpenGL -framework /System/Library/Frameworks/AppKit.framework/Appkit)
target_link_libraries(cub3D LINK_PUBLIC libm.so libc.so libmlx.a libX11.so libXext.so bsd.so)