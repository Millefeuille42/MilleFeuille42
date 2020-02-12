# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 13:26:44 by mlabouri          #+#    #+#              #
#    Updated: 2020/02/12 09:53:34 by mlabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./trees/flags_disp_tree.c trees/flags_val_tree.c trees/args_length_tree.c trees/convs_disp_tree.c											\
			./length_utils/ft_nbr_len.c length_utils/ft_strlen.c length_utils/ft_nbrbase_len.c															\
			./args_utils/ft_args.c args_utils/ft_disp.c																									\
			./var_utils/ft_c_in_set.c var_utils/ft_isdigit.c var_utils/ft_power.c var_utils/ft_szero.c var_utils/int_abs.c var_utils/ft_atoi_mk2.c 		\
			./display_utils/ft_putchar_fd.c display_utils/ft_putnbr_fd.c display_utils/ft_putnbrbase.c display_utils/ft_putstr_fd.c						\
			./ft_printf.c

OBJS	=	${SRCS:.c=.o}

INCL	=	./

NAME	=	libftprintf.a

COMPILE	=	gcc

LIB		=	ar rc

RM		=	rm -f

FLAGS	=	 -I ${INCL}

.c.o	:
			${COMPILE} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME) :	${OBJS}
			${LIB} ${NAME} ${OBJS}

all		:	$(NAME)

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

o		:	re
			${MAKE} fclean

.PHONY	:	all clean fclean re
