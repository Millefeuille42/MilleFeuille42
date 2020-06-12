# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 09:03:17 by dboyer            #+#    #+#              #
#    Updated: 2020/06/12 11:15:38 by dboyer           ###   ########.fr        #
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

SRCS    			=	./srcs/ft_add_env.c									\
                     	./srcs/ft_clear_env.c								\
                     	./srcs/ft_display_env.c								\
                     	./srcs/ft_env_get.c									\
                     	./srcs/ft_env_remove.c								\
                     	./srcs/run.c										\
                        ./srcs/ft_exec.c									\
                     	./srcs/ft_getcwd.c									\
                     	./srcs/ft_shell.c									\
                     	./srcs/ft_show_prompt.c								\
                        ./srcs/parsing/parse_line.c							\
                        ./srcs/utils/array_len.c							\
                     	./srcs/utils/ft_delete_entry.c

INCLUDES			=	-I ./includes/										\
						${LIBRARY_INCLUDES}

HEADERS				=	./includes/minishell.h								\
						${LIBRARY_HEADERS}

OBJS_MAIN			= 	$(MAIN:.c=.o)
OBJS				= 	$(SRCS:.c=.o)

################################################################################
#								COMPILATION
################################################################################

CFLAGS  			= 	-Werror -Wall -Wextra -Ofast ${INCLUDES}
CC      			= 	clang
RM      			= 	rm -f

################################################################################
#								Minishell Rules
################################################################################

%.o: %.c ${HEADERS}
	$(CC) $(CFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) :	$(OBJS) $(OBJS_MAIN)
	make -C "./libs/libft/"
	make -C "./libs/lib_ft_list/"
	make -C "./libs/libft_string/"
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
	make -C ./libs/libft/

./libs/lib_ft_list/libftlist.a		:
	make -C ./libs/lib_ft_list/

./libs/libft_string/libftstring.a	:
	make -C ./libs/libft_string/

################################################################################
#									LIBS RULES
################################################################################

libs		:
	make -C "./libs/libft/"
	make -C "./libs/lib_ft_list/"
	make -C "./libs/libft_string/"

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

run 	:	all
	./${NAME}

norm	:	fclean
	~/.norminette/norminette.rb

.PHONY  :	all clean fclean re bonus%