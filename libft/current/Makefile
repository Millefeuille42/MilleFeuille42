# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 13:26:44 by mlabouri          #+#    #+#              #
#    Updated: 2019/11/20 19:19:50 by mlabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./ft_atoi.c					\
			./ft_bzero.c				\
			./ft_calloc.c				\
			./ft_isalnum.c				\
			./ft_isalpha.c				\
			./ft_isascii.c				\
			./ft_isdigit.c				\
			./ft_isprint.c				\
			./ft_itoa.c					\
			./ft_memccpy.c				\
			./ft_memchr.c				\
			./ft_memcmp.c				\
			./ft_memcpy.c				\
			./ft_memmove.c				\
			./ft_memset.c				\
			./ft_putchar_fd.c			\
			./ft_putendl_fd.c			\
			./ft_putnbr_fd.c			\
			./ft_putstr_fd.c			\
			./ft_split.c				\
			./ft_strchr.c				\
			./ft_strdup.c				\
			./ft_strjoin.c				\
			./ft_strlcat.c				\
			./ft_strlcpy.c				\
			./ft_strlen.c				\
			./ft_strmapi.c				\
			./ft_strncmp.c				\
			./ft_strnstr.c				\
			./ft_strrchr.c				\
			./ft_strtrim.c				\
			./ft_substr.c				\
			./ft_tolower.c				\
			./ft_toupper.c				\
			./ft_cinset.c				\
			./ft_isspace.c

SRCS_B	=	${SRCS}						\
			./ft_lstadd_back_bonus.c	\
			./ft_lstadd_front_bonus.c	\
			./ft_lstiter_bonus.c		\
			./ft_lstlast_bonus.c		\
			./ft_lstnew_bonus.c			\
			./ft_lstsize_bonus.c

OBJS	=	${SRCS:.c=.o}

OBJS_B	=	${SRCS_B:.c=.o}

INCL	=	./

NAME	=	libft.a

COMPILE	=	gcc

LIB		=	ar rc

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror -I ${INCL}

.c.o	:
			${COMPILE} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME) :	${OBJS}
			${LIB} ${NAME} ${OBJS}

all		:	$(NAME)

clean	:
			${RM} ${OBJS_B}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

o		:	re
			${MAKE} fclean

bonus	:	${OBJS_B}
			${LIB} ${NAME} ${OBJS_B}

.PHONY	:	all clean fclean re bonus
