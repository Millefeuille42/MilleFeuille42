# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 12:19:51 by mlabouri          #+#    #+#              #
#    Updated: 2020/06/24 14:53:31 by mlabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################### OS DETECTOR ####################################
LIBS	=	-L . -lmlx
FRW		:=
INCL	:=	-I ./includes/ -I /usr/local/include

UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LIBS += -L /usr/lib/ -lbsd -lm -lc -lX11 -lmlx -lXext
	endif
	ifeq ($(UNAME_S),Darwin)
		FRW += -L. -lmlx -framework OpenGL -framework Appkit
	endif
################################################################################

SRCS	= 	./main.c											\
        	./init_conf.c										\
        	./parsing/cub_parser.c								\
        	./parsing/parsing_methods/parsing_methods_1.c		\
        	./parsing/parsing_methods/parsing_methods_2.c		\
        	./parsing/parsing_methods/parsing_methods_3.c		\
        	./parsing/parsing_methods/error_check_methods.c		\
        	./parsing/parsing_methods/error_check_methods_2.c	\
        	./parsing/parsing_methods/error_check_methods_3.c	\
			./parsing/parsing_methods/sprites_init.c			\
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
			./utils/vector_matrix.c								\
			./graphical/drawing/drawing_utils.c					\
        	./graphical/drawing/drawing_utils_2.c				\
        	./graphical/hooks/events.c							\
        	./graphical/hooks/keyboard_hooks.c					\
        	./graphical/hooks/keyboard_functions.c				\
        	./graphical/hooks/keyboard_functions_2.c			\
			./graphical/hooks/game_loop.c						\
        	./graphical/rays/ray.c								\
			./graphical/rays/sprites_calculations.c				\
			./graphical/minimap.c								\
			./graphical/drawing/texturing.c						\
			./graphical/drawing/sprites_rendering.c				\
			./graphical/drawing/buffer_commands.c				\
			./bitmap/ft_bmp.c

HEAD	=	./includes/cub3d.h									\
			./includes/get_next_line.h							\
			./includes/parsing.h								\
			./includes/graphical.h								\
			./includes/bitmap.h									\

OBJS	=	${SRCS:.c=.o}

COMPILE	=	clang
FLAGS	=	-Wall -Wextra -Werror -Ofast

RM		=	rm -f

NAME	=	cub3D

.c.o	:
			${COMPILE} ${FLAGS} ${INCL} -c $< -o $@

${NAME} :	${OBJS} ${HEAD}
			${COMPILE} ${FLAGS} -o ${NAME} ${OBJS} ${LIBS} ${INCL} ${FRW}

all		:	${NAME}

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

o		:	re
			${MAKE} clean

play	:	${NAME}
			./cub3D ./sample.cub

norm	:	${SRCS} ${HEAD}
			~/.norminette/norminette.rb $^

.PHONY	:	all clean fclean re norm play
