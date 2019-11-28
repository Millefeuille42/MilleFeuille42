cmake_minimum_required(VERSION 3.13)

project(ft_printf)
set(CMAKE_CXX_STANDARD 14)

add_executable(ft_printf ft_printf.c
        args_utils/ft_count_args.c args_utils/ft_val_flags.c
        string_utils/ft_c_in_set.c string_utils/ft_strlen.c
        )