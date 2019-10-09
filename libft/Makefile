# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 13:26:44 by mlabouri          #+#    #+#              #
#    Updated: 2019/10/09 13:42:40 by mlabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./srcs/ft_putchar.c	\
			./srcs/ft_swap.c	\
			./srcs/ft_putstr.c	\
			./srcs/ft_strlen.c	\
			./srcs/ft_strcmp.c

OBJS	=	${SRCS:.c=.o}

INCL	=	includes/ft.h

NAME	=	libft.a

COMPILE	=	gcc

LIB		=	ar rc

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror -I ${INCL}

.c.o	:
			${COMPILE} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME} :	${OBJS}
			${LIB} ${NAME} ${OBJS}

all		:	${NAME}

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

bonus	:

.PHONY	:	all clean fclean re
