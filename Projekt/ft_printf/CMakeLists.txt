cmake_minimum_required(VERSION 3.13)

project(ft_printf)
set(CMAKE_CXX_STANDARD 14)

add_executable(ft_printf ft_printf.c
        args_utils/ft_val_flag.c args_utils/flags_tree.c args_utils/convs_tree.c
        string_utils/ft_c_in_set.c string_utils/ft_strlen.c
        display_utils/ft_putstr_fd.c display_utils/ft_putnbr_fd.c
        )