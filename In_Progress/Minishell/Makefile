# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 12:19:51 by mlabouri          #+#    #+#              #
#    Updated: 2020/05/14 15:58:05 by mlabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	./main.c

OBJS	=	${SRCS:.c=.o}
# INCL	=	./includes/

LSTDRT	=	-L /usr/lib/ -lX11 -lbsd -lm -lc

COMPILE	=	clang
FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

NAME	=	Minishell

.c.o	:
			${COMPILE} ${FLAGS} -c $< -o $@ -O3

${NAME} :	${OBJS}
			${COMPILE} ${FLAGS} -o ${NAME} ${OBJS} ${LSTDRT} ${LX} ${LMLX} -O3

all		:	${NAME}

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

o		:	re
			${MAKE} clean

norm	:	${SRCS} #${INCL}
			~/.norminette/norminette.rb $^
.PHONY	:	all clean fclean re norm
