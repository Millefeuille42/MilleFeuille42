set( 	SOURCE_LIBFT_STRING

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



set(    SOURCE_MINISHELL

		../../In_Progress/Minishell/srcs/main.c

		)

add_executable(minishell ${SOURCE_LIBFT_STRING} ${SOURCE_MINISHELL})