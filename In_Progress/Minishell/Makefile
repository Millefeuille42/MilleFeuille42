# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 09:03:17 by dboyer            #+#    #+#              #
#    Updated: 2020/06/10 11:42:42 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    			=	minishell

SRCS    			=	./srcs/ft_getcwd.c \
						./srcs/pwd.c

LIBFT_PATH			= 	"./libs/libft/"
LIB_FT_LIST_PATH	= 	"./libs/lib_ft_list/"
LIB_FTSTRING_PATH	= 	"./libs/libft_string/"

MAIN 				= 	srcs/main.c

OBJS_MAIN 			= 	$(MAIN:.c=.o)
OBJS    			= 	$(SRCS:.c=.o)

LIBRARY	 			=	-L ./libs/lib_ft_list -lftlist	\
		  				-L ./libs/libft -lft			\
		  				-L ./libs/libft -lftstring		\

CC      			= 	clang

RM      			= 	rm -f

HEADERS 			= 	-I ./includes/ -I ./libs/libft/includes -I ./libs/lib_ft_list/includes

CFLAGS  			= 	-Werror -Wall -Wextra -Ofast -pedantic-errors ${HEADERS}

INCS = ./libs/libft/includes/libft.h ./libs/lib_ft_list/includes/ft_list.h ./includes/minishell.h 

################################################################################
#									cube3d make
################################################################################

%.o: %.c ${INCS}
	$(CC) $(CFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) : $(OBJS) $(OBJS_MAIN)
	make -C $(LIBFT_PATH)
	make -C $(LIB_FT_LIST_PATH)
	make -C $(LIB_FTSTRING_PATH)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_MAIN} ${LIBRARY}

clean   :
	make clean -C $(LIBFT_PATH)
	make clean -C $(LIB_FT_LIST_PATH)
	make clean -C $(LIB_FTSTRING_PATH)
	$(RM) $(OBJS)
	$(RM) ${OBJS_MAIN}

fclean  : clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(LIB_FT_LIST_PATH)
	make fclean -C $(LIB_FTSTRING_PATH)
	$(RM) $(NAME)

run 	: all
	./${NAME}

re      : fclean all

################################################################################
#												Extra make
################################################################################

norm: fclean
	~/.norminette/norminette.rb

.PHONY  :	all clean fclean re bonus%
