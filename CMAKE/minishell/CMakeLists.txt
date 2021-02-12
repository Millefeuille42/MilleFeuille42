add_library( LIBFT_STRING

		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_clear.c
		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_islower.c
		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_isupper.c
		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_memcpy.c
		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_memmove.c
		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_strdup.c
		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_strjoin.c
		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_strlcat.c
		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_strlcpy.c
		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_strncmp.c
		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_strnstr.c
		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_tolower.c
		../../Finished/minishell/libs/libft_string/srcs/dependencies/ft_toupper.c

		../../Finished/minishell/libs/libft_string/srcs/functions/ft_move_until.c
		../../Finished/minishell/libs/libft_string/srcs/functions/ft_parse.c
		../../Finished/minishell/libs/libft_string/srcs/functions/ft_str_isequal.c
		../../Finished/minishell/libs/libft_string/srcs/functions/ft_strlen.c

		../../Finished/minishell/libs/libft_string/srcs/includes/libft_string.h
		../../Finished/minishell/libs/libft_string/srcs/includes/string_object.h

		../../Finished/minishell/libs/libft_string/srcs/string/ft_clear_string.c
		../../Finished/minishell/libs/libft_string/srcs/string/ft_delete.c
		../../Finished/minishell/libs/libft_string/srcs/string/ft_prepend.c
		../../Finished/minishell/libs/libft_string/srcs/string/ft_push_string.c
		../../Finished/minishell/libs/libft_string/srcs/string/ft_replace.c
		../../Finished/minishell/libs/libft_string/srcs/string/ft_string.c
		../../Finished/minishell/libs/libft_string/srcs/string/ft_string_low.c
		../../Finished/minishell/libs/libft_string/srcs/string/ft_string_up.c

		)

add_library( LIBFT

		../../Finished/minishell/libs/libft/includes/libft.h
		../../Finished/minishell/libs/libft/includes/libft_objects.h
		../../Finished/minishell/libs/libft/srcs/ft_abs.c
		../../Finished/minishell/libs/libft/srcs/ft_atoi.c
		../../Finished/minishell/libs/libft/srcs/ft_bzero.c
		../../Finished/minishell/libs/libft/srcs/ft_calloc.c
		../../Finished/minishell/libs/libft/srcs/ft_cinset.c
		../../Finished/minishell/libs/libft/srcs/ft_format.c
		../../Finished/minishell/libs/libft/srcs/ft_getflag.c
		../../Finished/minishell/libs/libft/srcs/ft_isalnum.c
		../../Finished/minishell/libs/libft/srcs/ft_isalpha.c
		../../Finished/minishell/libs/libft/srcs/ft_isascii.c
		../../Finished/minishell/libs/libft/srcs/ft_isdigit.c
		../../Finished/minishell/libs/libft/srcs/ft_isflag.c
		../../Finished/minishell/libs/libft/srcs/ft_islower.c
		../../Finished/minishell/libs/libft/srcs/ft_isprint.c
		../../Finished/minishell/libs/libft/srcs/ft_isspace.c
		../../Finished/minishell/libs/libft/srcs/ft_isupper.c
		../../Finished/minishell/libs/libft/srcs/ft_itoa.c
		../../Finished/minishell/libs/libft/srcs/ft_memccpy.c
		../../Finished/minishell/libs/libft/srcs/ft_memchr.c
		../../Finished/minishell/libs/libft/srcs/ft_memcmp.c
		../../Finished/minishell/libs/libft/srcs/ft_memcpy.c
		../../Finished/minishell/libs/libft/srcs/ft_memmove.c
		../../Finished/minishell/libs/libft/srcs/ft_memset.c
		../../Finished/minishell/libs/libft/srcs/ft_minmax.c
		../../Finished/minishell/libs/libft/srcs/ft_minmax_memory.c
		../../Finished/minishell/libs/libft/srcs/ft_minmax_nb.c
		../../Finished/minishell/libs/libft/srcs/ft_minmax_nb_hex.c
		../../Finished/minishell/libs/libft/srcs/ft_minmax_str.c
		../../Finished/minishell/libs/libft/srcs/ft_minmax_unsigned_nb.c
		../../Finished/minishell/libs/libft/srcs/ft_nbrlen.c
		../../Finished/minishell/libs/libft/srcs/ft_nbrlen_base.c
		../../Finished/minishell/libs/libft/srcs/ft_nbrlen_unsigned.c
		../../Finished/minishell/libs/libft/srcs/ft_parsing.c
		../../Finished/minishell/libs/libft/srcs/ft_print.c
		../../Finished/minishell/libs/libft/srcs/ft_print_char.c
		../../Finished/minishell/libs/libft/srcs/ft_print_memory.c
		../../Finished/minishell/libs/libft/srcs/ft_print_nb.c
		../../Finished/minishell/libs/libft/srcs/ft_print_nb_hex.c
		../../Finished/minishell/libs/libft/srcs/ft_print_percent.c
		../../Finished/minishell/libs/libft/srcs/ft_print_space_after.c
		../../Finished/minishell/libs/libft/srcs/ft_print_space_before.c
		../../Finished/minishell/libs/libft/srcs/ft_print_str.c
		../../Finished/minishell/libs/libft/srcs/ft_print_unsigned_nb.c
		../../Finished/minishell/libs/libft/srcs/ft_print_zero_padding.c
		../../Finished/minishell/libs/libft/srcs/ft_printf.c
		../../Finished/minishell/libs/libft/srcs/ft_putchar.c
		../../Finished/minishell/libs/libft/srcs/ft_putchar_fd.c
		../../Finished/minishell/libs/libft/srcs/ft_putendl_fd.c
		../../Finished/minishell/libs/libft/srcs/ft_putnbr_base.c
		../../Finished/minishell/libs/libft/srcs/ft_putnbr_fd.c
		../../Finished/minishell/libs/libft/srcs/ft_putnbr_hex.c
		../../Finished/minishell/libs/libft/srcs/ft_putnbr_unsigned.c
		../../Finished/minishell/libs/libft/srcs/ft_putnstr.c
		../../Finished/minishell/libs/libft/srcs/ft_putstr.c
		../../Finished/minishell/libs/libft/srcs/ft_putstr_fd.c
		../../Finished/minishell/libs/libft/srcs/ft_split.c
		../../Finished/minishell/libs/libft/srcs/ft_split_clean.c
		../../Finished/minishell/libs/libft/srcs/ft_str_tolower.c
		../../Finished/minishell/libs/libft/srcs/ft_str_toupper.c
		../../Finished/minishell/libs/libft/srcs/ft_strchr.c
		../../Finished/minishell/libs/libft/srcs/ft_strdup.c
		../../Finished/minishell/libs/libft/srcs/ft_strjoin.c
		../../Finished/minishell/libs/libft/srcs/ft_strlcat.c
		../../Finished/minishell/libs/libft/srcs/ft_strlcpy.c
		../../Finished/minishell/libs/libft/srcs/ft_strlen.c
		../../Finished/minishell/libs/libft/srcs/ft_strmapi.c
		../../Finished/minishell/libs/libft/srcs/ft_strncmp.c
		../../Finished/minishell/libs/libft/srcs/ft_strnstr.c
		../../Finished/minishell/libs/libft/srcs/ft_strrchr.c
		../../Finished/minishell/libs/libft/srcs/ft_strrev.c
		../../Finished/minishell/libs/libft/srcs/ft_strtrim.c
		../../Finished/minishell/libs/libft/srcs/ft_substr.c
		../../Finished/minishell/libs/libft/srcs/ft_tolower.c
		../../Finished/minishell/libs/libft/srcs/ft_toupper.c
		../../Finished/minishell/libs/libft/srcs/get_next_line.c

		)

add_library( LIB_FT_LIST

		../../Finished/minishell/libs/lib_ft_list/includes/ft_list.h
		../../Finished/minishell/libs/lib_ft_list/srcs/ft_add_back.c
		../../Finished/minishell/libs/lib_ft_list/srcs/ft_clear.c
		../../Finished/minishell/libs/lib_ft_list/srcs/ft_concat.c
		../../Finished/minishell/libs/lib_ft_list/srcs/ft_del.c
		../../Finished/minishell/libs/lib_ft_list/srcs/ft_get_list_element.c
		../../Finished/minishell/libs/lib_ft_list/srcs/ft_insert_before.c
		../../Finished/minishell/libs/lib_ft_list/srcs/ft_list.c
		../../Finished/minishell/libs/lib_ft_list/srcs/ft_list_copy.c
		../../Finished/minishell/libs/lib_ft_list/srcs/ft_list_iter.c
		../../Finished/minishell/libs/lib_ft_list/srcs/ft_list_iter_inv.c
		../../Finished/minishell/libs/lib_ft_list/srcs/ft_new_element.c
		../../Finished/minishell/libs/lib_ft_list/srcs/ft_search.c

		)

set(    SOURCE_minishell

		../../Finished/minishell/srcs/ft_add_env.c
		../../Finished/minishell/srcs/ft_clear_env.c
		../../Finished/minishell/srcs/ft_display_env.c
		../../Finished/minishell/srcs/ft_env_get.c
		../../Finished/minishell/srcs/ft_env_remove.c
		../../Finished/minishell/srcs/ft_replace_env.c
		../../Finished/minishell/srcs/ft_extract_env.c

		../../Finished/minishell/srcs/parsing/check_command.c
		../../Finished/minishell/srcs/parsing/path_parsing.c
		../../Finished/minishell/srcs/parsing/get_next.c
		../../Finished/minishell/srcs/parsing/get_next_arg.c
		../../Finished/minishell/srcs/parsing/parsing_utils.c
		../../Finished/minishell/srcs/parsing/get_next_command.c
		../../Finished/minishell/srcs/parsing/parsing.c

		../../Finished/minishell/srcs/utils/file_exists.c
		../../Finished/minishell/srcs/utils/ft_len.c

		../../Finished/minishell/srcs/functions/ft_pwd.c
		../../Finished/minishell/srcs/functions/ft_export.c
		../../Finished/minishell/srcs/functions/ft_unset.c
		../../Finished/minishell/srcs/functions/ft_env.c
		../../Finished/minishell/srcs/functions/ft_cd.c
		../../Finished/minishell/srcs/functions/ft_echo.c

		../../Finished/minishell/srcs/ft_test_builtin.c
		../../Finished/minishell/srcs/ft_read_input.c
		../../Finished/minishell/srcs/ft_replace_input.c
		../../Finished/minishell/srcs/ft_remove_char.c
		../../Finished/minishell/srcs/ft_exec.c
		../../Finished/minishell/srcs/ft_getcwd.c
		../../Finished/minishell/srcs/ft_shell.c
		../../Finished/minishell/srcs/ft_show_prompt.c
		../../Finished/minishell/srcs/run.c
		../../Finished/minishell/srcs/main.c
		../../Finished/minishell/srcs/parsing/parse_redir.c ../../Finished/minishell/srcs/parsing/parse_redir_2.c ../../Finished/minishell/srcs/utils/ft_swap.c ../../Finished/minishell/srcs/parsing/clean_escape.c ../../Finished/minishell/srcs/parsing/delete_char.c)

add_executable(minishell
		${SOURCE_minishell}
		)

target_link_libraries(minishell LIBFT LIB_FT_LIST LIBFT_STRING)

include_directories(
		../../Finished/minishell/includes
		../../Finished/minishell/libs/libft_string/srcs/includes
		../../Finished/minishell/libs/libft/includes
		../../Finished/minishell/libs/lib_ft_list/includes
)