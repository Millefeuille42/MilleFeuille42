# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: millefeuille </var/spool/mail/millefe      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 18:34:32 by millefeui         #+#    #+#              #
#    Updated: 2020/04/30 18:34:44 by millefeui        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	./main.c											\
			./init_conf.c										\
			./parsing/cub_parser.c								\
			./parsing/parsing_methods/parsing_methods_1.c		\
			./parsing/parsing_methods/parsing_methods_2.c		\
			./parsing/parsing_methods/parsing_methods_3.c		\
			./parsing/parsing_methods/error_check_methods.c		\
			./parsing/parsing_methods/error_check_methods_2.c	\
			./parsing/GNL/get_next_line_utils.c					\
			./parsing/GNL/get_next_line.c						\
			./utils/ft_strdup.c									\
			./utils/ft_strjoin.c								\
			./utils/ft_strnstr.c								\
			./utils/ft_strlen.c									\
			./utils/ft_isdigit.c								\
			./utils/ft_atoi_mk2.c								\
			./utils/ft_c_in_set.c								\
			./utils/ft_substr.c									\
			./utils/ft_split.c									\
			./utils/ft_putstr_fd.c								\
			./graphical/drawing/drawing_utils.c					\
			./graphical/drawing/drawing_utils_2.c				\
			./graphical/hooks/events.c							\
			./graphical/hooks/keyboard_hooks.c					\
			./graphical/hooks/keyboard_functions.c				\
			./graphical/hooks/keyboard_functions_2.c			\
			./graphical/rays/ray.c								\
			./graphical/rays/ray_utils.c						\
			./graphical/minimap.c								\
			./graphical/drawing/texturing.c

OBJS	=	${SRCS:.c=.o}
INCL	=	./includes/

LSTDRT	=	-L /usr/lib/ -lX11 -lbsd -lm -lc
LX		=	-lX11 -lmlx -lXext
LMLX	=	-L /usr/local/lib/ -lmlx

COMPILE	=	clang
FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

NAME	=	cub3D

.c.o	:
			${COMPILE} ${FLAGS} -c $< -o $@

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

play	:	${NAME} clean
			./cub3D ./sample.cub

win_{$NAME}		:	${OBJS}


norm	:	${SRCS} ${INCL}
			~/.norminette/norminette.rb $^
.PHONY	:	all clean fclean re norm play
