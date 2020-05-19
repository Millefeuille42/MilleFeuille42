# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             #
#   Updated: 2020/04/10 15:07:13 by mlabouri         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

SRCS	=	./ft_read.s     \
            	./ft_write.s    \
           	./ft_strlen.s   \
           	./ft_strcmp.s   \
          	./ft_strcpy.s   \
          	./ft_strdup.s

OBJS	=	${SRCS:.s=.o}

NAME	=	libasm.a

COMPILE	=	nasm

LIB		= ar rcs

RM		= rm -f

FLAGS	=	-f elf64

%.o:    %.s
			${COMPILE} ${FLAGS} $<

$(NAME) :	${OBJS}
			${LIB} ${NAME} ${OBJS}
			ranlib ${NAME}

all		:	$(NAME)

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME} ./test/test.out

re		:	fclean all

o		:	re
			${MAKE} fclean

test		:	all
			clang -no-pie ./test/main.c -L ./ -lasm -o test/test.out; ./test/test.out

.PHONY	:	all clean fclean re
