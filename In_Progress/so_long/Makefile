SRCS	= 	                main.c																		\
                    		utils/GNL/get_next_line.c utils/GNL/get_next_line_utils.c					\
                            utils/ft_strlen.c utils/ft_strnstr.c utils/ft_putstr_fd.c					\
                            utils/ret_error.c utils/ft_c_in_set.c utils/ft_putnbr_fd.c					\
                    		utils/lists/list.c utils/lists/element.c									\
                            get_and_check/map_checks.c get_and_check/map.c get_and_check/arguments.c	\
                    		get_and_check/utils.c														\
                    		window/window_start.c window/window_hooks.c window/window_utils.c			\
                    		window/drawing.c window/movement.c window/player_pos.c

HEAD	=	./so_long.h utils/GNL/get_next_line.h utils/lists/lists.h mlx/mlx.h /usr/include/X11/X.h /usr/include/X11/xlib.h

OBJS	=	${SRCS:.c=.o}

INCL	=	-I ./ -I ./utils/GNL -I ./utils/list/
I_MLX	=	-I /usr/include/X11 -I ./mlx

LMLX	=	-L /usr/lib/x86_64-linux-gnu -lXext -lX11 -L ./mlx -lmlx

COMPILE	=	clang
FLAGS	=	-Ofast -Wall -Wextra -Werror -pedantic

RM		=	rm -f

NAME	=	so_long

.c.o	:
			${COMPILE} ${FLAGS} -c $< -o $@

${NAME} :	$(OBJS) $(HEADS)
			${COMPILE} ${FLAGS} -o ${NAME} ${OBJS} ${INCL} ${LMLX} ${I_MLX}

all		:	${NAME}

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

o		:	re
			${MAKE} clean

run		: all
			./${NAME} ./test.ber
			make clean

.PHONY	:	all clean fclean re
