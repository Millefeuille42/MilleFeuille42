# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 09:03:17 by dboyer            #+#    #+#              #
#    Updated: 2020/06/11 11:50:26 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    			=	cd

LIBFT_PATH			= 	"../../../libs/libft/"

MAIN 				= 	main.c

OBJS_MAIN 			= 	$(MAIN:.c=.o)

LIBRARY	 			=	-L ../../../libs/libft -lft

CC      			= 	clang

RM      			= 	rm -f

HEADERS 			=   -I ../../../libs/libft/includes

CFLAGS  			= 	-Werror -Wall -Wextra -Ofast -pedantic-errors ${HEADERS}

INCS				= ../../../libs/libft/includes/libft.h

################################################################################
#									cd make
################################################################################

%.o: %.c ${INCS}
	$(CC) $(CFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) : $(OBJS_MAIN)
	make -C $(LIBFT_PATH)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS_MAIN} ${LIBRARY}

clean   :
	make clean -C $(LIBFT_PATH)
	$(RM) ${OBJS_MAIN}

fclean  : clean
	make fclean -C $(LIBFT_PATH)
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
