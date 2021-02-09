# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 09:03:17 by dboyer            #+#    #+#              #
#    Updated: 2020/10/28 16:08:55 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
#									LIBS
################################################################################

LIBRARY_LINKS		=	-L ./libs/libft/ -lft								\
				-L ./libs/lib_ft_list/ -lftlist						\
				-L ./libs/libft_string/ -lftstring

LIBRARY_INCLUDES	=  	-I ./libs/libft/includes 							\
				-I ./libs/lib_ft_list/includes						\
				-I ./libs/libft_string/srcs/includes

LIBRARY_HEADERS		=	./libs/libft/includes/libft.h						\
				./libs/lib_ft_list/includes/ft_list.h				\
				./libs/libft_string/srcs/includes/libft_string.h

################################################################################
#									SOURCES
################################################################################

NAME    			=	minishell

MAIN				= 	./srcs/main.c

SRCS    			=	./srcs/builtins/ft_cd.c                      \
                        ./srcs/builtins/ft_echo.c                    \
                        ./srcs/builtins/ft_env.c                     \
                        ./srcs/builtins/ft_exit.c                    \
                        ./srcs/builtins/ft_export.c                  \
                        ./srcs/builtins/ft_getcwd.c                  \
                        ./srcs/builtins/ft_pwd.c                     \
                        ./srcs/builtins/ft_unset.c                   \
                        ./srcs/env/ft_add_env.c                      \
                        ./srcs/env/ft_clear_env.c                    \
                        ./srcs/env/ft_env_get.c                      \
                        ./srcs/env/ft_env_remove.c                   \
                        ./srcs/env/ft_extract_env.c                  \
                        ./srcs/env/ft_replace_env.c                  \
                        ./srcs/env/ft_start_env.c                    \
                        ./srcs/env/ft_display_env.c                  \
                        ./srcs/env/ft_ret_env.c                  	 \
                        ./srcs/parsing/ft_close_fd.c                 \
                        ./srcs/parsing/ft_command.c                  \
                        ./srcs/parsing/ft_exec.c                     \
                        ./srcs/parsing/ft_del_cmd.c                  \
                        ./srcs/parsing/ft_find_command.c             \
                        ./srcs/parsing/ft_get_command.c              \
                        ./srcs/parsing/ft_handle_pipe.c              \
                        ./srcs/parsing/ft_handle_stdin_redirect.c    \
                        ./srcs/parsing/ft_handle_stdout_redirect.c   \
                        ./srcs/parsing/ft_is_sep_and_space.c         \
                        ./srcs/parsing/ft_isseparator.c              \
                        ./srcs/parsing/ft_sort_arg.c                 \
                        ./srcs/parsing/ft_parse_args.c               \
                        ./srcs/parsing/ft_sort_arg_cleaning.c        \
                        ./srcs/parsing/ft_sort_arg_utils.c           \
                        ./srcs/parsing/ft_test_builtin.c             \
                        ./srcs/parsing/ft_parse_input.c              \
                        ./srcs/parsing/ft_is_escape.c                \
                        ./srcs/parsing/ft_safe_extract.c			 \
                        ./srcs/parsing/ft_iscommand.c				 \
                        ./srcs/parsing/ft_syntax_error.c				 \
                        ./srcs/parsing/ft_isarg.c					 \
			./srcs/shell/ft_check_input.c		     \
                        ./srcs/shell/ft_clean_shell.c                \
                        ./srcs/shell/ft_read_input.c                 \
                        ./srcs/shell/ft_remove_char.c                \
                        ./srcs/shell/ft_replace_input.c              \
                        ./srcs/shell/ft_run.c                        \
                        ./srcs/shell/ft_shell.c                      \
                        ./srcs/shell/ft_show_prompt.c                \
                        ./srcs/utils/ft_file_exists.c                \
                        ./srcs/utils/ft_len.c                        \
                        ./srcs/utils/safe_free.c                     \
                        ./srcs/utils/ft_swap.c                       \

INCLUDES			=	-I ./includes/ 										\
					${LIBRARY_INCLUDES}

HEADERS				=	./includes/minishell.h								\
					${LIBRARY_HEADERS}

OBJS_MAIN			= 	$(MAIN:.c=.o)
OBJS				= 	$(SRCS:.c=.o)

################################################################################
#								COMPILATION
################################################################################

CFLAGS  			= 	-Werror -Wall -Wextra -O3 ${INCLUDES}
CC      			= 	clang
RM      			= 	rm -f

################################################################################
#								Minishell Rules
################################################################################

%.o: %.c ${HEADERS}
	$(CC) $(CFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) :	$(OBJS) $(OBJS_MAIN)
	make -j -C "./libs/libft/"
	make -j -C "./libs/lib_ft_list/"
	make -j -C "./libs/libft_string/"
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_MAIN} ${LIBRARY_LINKS}

clean   :	libs_clean
	$(RM) $(OBJS)
	$(RM) ${OBJS_MAIN}

fclean  :	libs_fclean clean
	$(RM) $(NAME)

re      :	fclean all

################################################################################
#									LIBS DEPS RULES
################################################################################

./libs/libft/libft.a				:
	make -j -C ./libs/libft/

./libs/lib_ft_list/libftlist.a		:
	make -j -C ./libs/lib_ft_list/

./libs/libft_string/libftstring.a	:
	make -j -C ./libs/libft_string/

################################################################################
#									LIBS RULES
################################################################################

libs		:
	make -j -C "./libs/libft/"
	make -j -C "./libs/lib_ft_list/"
	make -j -C "./libs/libft_string/"

libs_clean	:
	make clean -C "./libs/libft/"
	make clean -C "./libs/lib_ft_list/"
	make clean -C "./libs/libft_string/"

libs_fclean	:
	make fclean -C "./libs/libft/"
	make fclean -C "./libs/lib_ft_list/"
	make fclean -C "./libs/libft_string/"

################################################################################
#									Extra Rules
################################################################################

clean_2	:
	$(RM) $(OBJS)
	$(RM) ${OBJS_MAIN}

run 	:	all
	./${NAME}

test 	:
	pip3 install -r requirements.txt && python3 main.py

norm	:	fclean
	~/.norminette/norminette.rb ${SRCS} ${HEADERS}

norm_42	:	fclean
	norminette ${SRCS} ${HEADERS}

fast	:
	make -j
.PHONY  :	all clean fclean re bonus%
