set(    SOURCE_CUB3D

        cub3D/main.c
        cub3D/init_conf.c

        cub3D/parsing/cub_parser.c
        cub3D/parsing/parsing_methods/parsing_methods_1.c
        cub3D/parsing/parsing_methods/parsing_methods_2.c
        cub3D/parsing/parsing_methods/parsing_methods_3.c
        cub3D/parsing/parsing_methods/error_check_methods.c
        cub3D/parsing/parsing_methods/error_check_methods_2.c
		cub3D/parsing/parsing_methods/sprites_init.c
		cub3D/parsing/GNL/get_next_line_utils.c
        cub3D/parsing/GNL/get_next_line.c
		cub3D/parsing/parsing_methods/error_check_methods_3.c

        cub3D/utils/ft_strdup.c
        cub3D/utils/ft_strjoin.c
        cub3D/utils/ft_strnstr.c
        cub3D/utils/ft_strlen.c
        cub3D/utils/ft_isdigit.c
        cub3D/utils/ft_atoi_mk2.c
        cub3D/utils/ft_c_in_set.c
        cub3D/utils/ft_substr.c
        cub3D/utils/ft_split.c
        cub3D/utils/ft_putstr_fd.c
		cub3D/utils/vector_matrix.c
		cub3D/utils/ft_atoi.c

		cub3D/graphical/drawing/drawing_utils.c
        cub3D/graphical/drawing/drawing_utils_2.c
        cub3D/graphical/hooks/events.c
        cub3D/graphical/hooks/keyboard_hooks.c
        cub3D/graphical/hooks/keyboard_functions.c
        cub3D/graphical/hooks/keyboard_functions_2.c
        cub3D/graphical/rays/ray.c
		cub3D/graphical/rays/sprites_calculations.c
		cub3D/graphical/minimap.c
		cub3D/graphical/drawing/texturing.c
		cub3D/graphical/drawing/sprites_rendering.c
		cub3D/graphical/drawing/buffer_commands.c

		cub3D/bitmap/ft_bmp.c

        PARENT_SCOPE)