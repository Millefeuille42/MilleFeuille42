project(ft_printf)

cmake_minimum_required(VERSION 3.15)

include_directories(includes)
add_executable(ft_printf
        ft_printf.c
        trees/flags_disp_tree.c trees/flags_val_tree.c trees/args_length_tree.c trees/convs_disp_tree.c
        length_utils/ft_nbr_len.c length_utils/ft_strlen.c length_utils/ft_nbrbase_len.c
        args_utils/ft_args.c var_utils/ft_atoi_mk2.c args_utils/ft_disp.c
        var_utils/ft_c_in_set.c var_utils/ft_isdigit.c var_utils/ft_power.c var_utils/ft_szero.c var_utils/int_abs.c
        display_utils/ft_putchar_fd.c display_utils/ft_putnbr_fd.c display_utils/ft_putnbrbase.c display_utils/ft_putstr_fd.c
        )