set(    SOURCE_PRINTF

        ../../Finished/ft_printf/ft_printf.c

        ../../Finished/ft_printf/args_utils/ft_disp.c
		../../Finished/ft_printf/args_utils/ft_args.c

        ../../Finished/ft_printf/display_utils/ft_putchar_fd.c
		../../Finished/ft_printf/display_utils/ft_putstr_fd.c
		../../Finished/ft_printf/display_utils/ft_putnbrbase.c
		../../Finished/ft_printf/display_utils/ft_putnbr_fd.c

        ../../Finished/ft_printf/length_utils/ft_nbr_len.c
		../../Finished/ft_printf/length_utils/ft_nbrbase_len.c
		../../Finished/ft_printf/length_utils/ft_strlen.c

        ../../Finished/ft_printf/trees/args_length_tree.c
		../../Finished/ft_printf/trees/flags_val_tree.c
		../../Finished/ft_printf/trees/flags_disp_tree.c
		../../Finished/ft_printf/trees/convs_disp_tree.c

        ../../Finished/ft_printf/var_utils/ft_atoi_mk2.c
		../../Finished/ft_printf/var_utils/ft_szero.c
		../../Finished/ft_printf/var_utils/int_abs.c
		../../Finished/ft_printf/var_utils/ft_isdigit.c
		../../Finished/ft_printf/var_utils/ft_c_in_set.c
		../../Finished/ft_printf/var_utils/ft_power.c

		)

add_executable(ft_printf ${SOURCE_PRINTF})