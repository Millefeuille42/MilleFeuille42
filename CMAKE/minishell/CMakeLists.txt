add_library( LIBFT_STRING

		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_clear.c
		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_islower.c
		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_isupper.c
		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_memcpy.c
		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_memmove.c
		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_strdup.c
		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_strjoin.c
		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_strlcat.c
		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_strlcpy.c
		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_strncmp.c
		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_strnstr.c
		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_tolower.c
		../../In_Progress/Minishell/libs/libft_string/srcs/dependencies/ft_toupper.c

		../../In_Progress/Minishell/libs/libft_string/srcs/functions/ft_move_until.c
		../../In_Progress/Minishell/libs/libft_string/srcs/functions/ft_parse.c
		../../In_Progress/Minishell/libs/libft_string/srcs/functions/ft_str_isequal.c
		../../In_Progress/Minishell/libs/libft_string/srcs/functions/ft_strlen.c

		../../In_Progress/Minishell/libs/libft_string/srcs/includes/libft_string.h
		../../In_Progress/Minishell/libs/libft_string/srcs/includes/string_object.h

		../../In_Progress/Minishell/libs/libft_string/srcs/string/ft_clear_string.c
		../../In_Progress/Minishell/libs/libft_string/srcs/string/ft_delete.c
		../../In_Progress/Minishell/libs/libft_string/srcs/string/ft_prepend.c
		../../In_Progress/Minishell/libs/libft_string/srcs/string/ft_push_string.c
		../../In_Progress/Minishell/libs/libft_string/srcs/string/ft_replace.c
		../../In_Progress/Minishell/libs/libft_string/srcs/string/ft_string.c
		../../In_Progress/Minishell/libs/libft_string/srcs/string/ft_string_low.c
		../../In_Progress/Minishell/libs/libft_string/srcs/string/ft_string_up.c

		)

add_library( LIBFT

		../../In_Progress/Minishell/libs/libft/includes/libft.h
		../../In_Progress/Minishell/libs/libft/includes/libft_objects.h
		../../In_Progress/Minishell/libs/libft/srcs/ft_abs.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_atoi.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_bzero.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_calloc.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_cinset.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_format.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_getflag.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_isalnum.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_isalpha.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_isascii.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_isdigit.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_isflag.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_islower.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_isprint.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_isspace.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_isupper.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_itoa.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_memccpy.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_memchr.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_memcmp.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_memcpy.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_memmove.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_memset.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_minmax.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_minmax_memory.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_minmax_nb.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_minmax_nb_hex.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_minmax_str.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_minmax_unsigned_nb.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_nbrlen.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_nbrlen_base.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_nbrlen_unsigned.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_parsing.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_print.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_print_char.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_print_memory.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_print_nb.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_print_nb_hex.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_print_percent.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_print_space_after.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_print_space_before.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_print_str.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_print_unsigned_nb.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_print_zero_padding.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_printf.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_putchar.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_putchar_fd.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_putendl_fd.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_putnbr_base.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_putnbr_fd.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_putnbr_hex.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_putnbr_unsigned.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_putnstr.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_putstr.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_putstr_fd.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_split.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_split_clean.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_str_tolower.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_str_toupper.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_strchr.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_strdup.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_strjoin.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_strlcat.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_strlcpy.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_strlen.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_strmapi.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_strncmp.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_strnstr.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_strrchr.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_strrev.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_strtrim.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_substr.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_tolower.c
		../../In_Progress/Minishell/libs/libft/srcs/ft_toupper.c
		../../In_Progress/Minishell/libs/libft/srcs/get_next_line.c

		)

add_library( LIB_FT_LIST

		../../In_Progress/Minishell/libs/lib_ft_list/includes/ft_list.h
		../../In_Progress/Minishell/libs/lib_ft_list/srcs/ft_add_back.c
		../../In_Progress/Minishell/libs/lib_ft_list/srcs/ft_clear.c
		../../In_Progress/Minishell/libs/lib_ft_list/srcs/ft_concat.c
		../../In_Progress/Minishell/libs/lib_ft_list/srcs/ft_del.c
		../../In_Progress/Minishell/libs/lib_ft_list/srcs/ft_get_list_element.c
		../../In_Progress/Minishell/libs/lib_ft_list/srcs/ft_insert_before.c
		../../In_Progress/Minishell/libs/lib_ft_list/srcs/ft_list.c
		../../In_Progress/Minishell/libs/lib_ft_list/srcs/ft_list_copy.c
		../../In_Progress/Minishell/libs/lib_ft_list/srcs/ft_list_iter.c
		../../In_Progress/Minishell/libs/lib_ft_list/srcs/ft_list_iter_inv.c
		../../In_Progress/Minishell/libs/lib_ft_list/srcs/ft_new_element.c
		../../In_Progress/Minishell/libs/lib_ft_list/srcs/ft_search.c

		)

set(    SOURCE_MINISHELL

		../../In_Progress/Minishell/srcs/ft_add_env.c
		../../In_Progress/Minishell/srcs/ft_clear_env.c
		../../In_Progress/Minishell/srcs/ft_display_env.c
		../../In_Progress/Minishell/srcs/ft_env_get.c
		../../In_Progress/Minishell/srcs/ft_env_remove.c
		../../In_Progress/Minishell/srcs/ft_replace_env.c
		../../In_Progress/Minishell/srcs/ft_extract_env.c

		../../In_Progress/Minishell/srcs/parsing/check_command.c
		../../In_Progress/Minishell/srcs/parsing/path_parsing.c
		../../In_Progress/Minishell/srcs/parsing/get_next.c
		../../In_Progress/Minishell/srcs/parsing/get_next_arg.c
		../../In_Progress/Minishell/srcs/parsing/parsing_utils.c
		../../In_Progress/Minishell/srcs/parsing/get_next_command.c
		../../In_Progress/Minishell/srcs/parsing/parsing.c

		../../In_Progress/Minishell/srcs/utils/file_exists.c
		../../In_Progress/Minishell/srcs/utils/ft_len.c

		../../In_Progress/Minishell/srcs/functions/ft_pwd.c
		../../In_Progress/Minishell/srcs/functions/ft_export.c
		../../In_Progress/Minishell/srcs/functions/ft_unset.c
		../../In_Progress/Minishell/srcs/functions/ft_env.c
		../../In_Progress/Minishell/srcs/functions/ft_cd.c
		../../In_Progress/Minishell/srcs/functions/ft_echo.c

		../../In_Progress/Minishell/srcs/ft_test_builtin.c
		../../In_Progress/Minishell/srcs/ft_read_input.c
		../../In_Progress/Minishell/srcs/ft_remove_char.c
		../../In_Progress/Minishell/srcs/ft_exec.c
		../../In_Progress/Minishell/srcs/ft_getcwd.c
		../../In_Progress/Minishell/srcs/ft_shell.c
		../../In_Progress/Minishell/srcs/ft_show_prompt.c
		../../In_Progress/Minishell/srcs/run.c
		../../In_Progress/Minishell/srcs/main.c
		)

add_executable(minishell
		${SOURCE_MINISHELL}
		)

target_link_libraries(minishell LIBFT LIB_FT_LIST LIBFT_STRING)

include_directories(
		../../In_Progress/Minishell/includes
		../../In_Progress/Minishell/libs/libft_string/srcs/includes
		../../In_Progress/Minishell/libs/libft/includes
		../../In_Progress/Minishell/libs/lib_ft_list/includes
)