cmake_minimum_required(VERSION 3.10)
project(42)
set(CMAKE_CXX_STANDARD 99)

set(    SOURCE_PRINTF
        ft_printf/ft_printf.c
        ft_printf/args_utils/ft_disp.c ft_printf/args_utils/ft_args.c
        ft_printf/display_utils/ft_putchar_fd.c ft_printf/display_utils/ft_putstr_fd.c ft_printf/display_utils/ft_putnbrbase.c ft_printf/display_utils/ft_putnbr_fd.c
        ft_printf/length_utils/ft_nbr_len.c ft_printf/length_utils/ft_nbrbase_len.c ft_printf/length_utils/ft_strlen.c
        ft_printf/trees/args_length_tree.c ft_printf/trees/flags_val_tree.c ft_printf/trees/flags_disp_tree.c ft_printf/trees/convs_disp_tree.c
        ft_printf/var_utils/ft_atoi_mk2.c ft_printf/var_utils/ft_szero.c ft_printf/var_utils/int_abs.c ft_printf/var_utils/ft_isdigit.c ft_printf/var_utils/ft_c_in_set.c ft_printf/var_utils/ft_power.c)

set(    SOURCE_GNL
        get_next_line/mlabouri/get_next_line.c get_next_line/mlabouri/get_next_line_utils.c
        get_next_line/mlabouri/get_next_line_bonus.c get_next_line/mlabouri/get_next_line_utils_bonus.c
        )


add_executable(ft_printf ${SOURCE_PRINTF})

add_executable(get_next_line ${SOURCE_GNL})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra --coverage")