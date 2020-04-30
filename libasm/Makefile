# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: millefeuille </var/spool/mail/millefe      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 18:34:33 by millefeui         #+#    #+#              #
#    Updated: 2020/04/30 18:34:45 by millefeui        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

INCL	=	./libasm.h

NAME	=	libasm.a

COMPILE	=	nasm

LIB		=	ar rc

RM		=	rm -f

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
			${RM} ${NAME}

re		:	fclean all

o		:	re
			${MAKE} fclean

.PHONY	:	all clean fclean re
