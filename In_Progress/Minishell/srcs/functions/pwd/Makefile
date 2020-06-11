# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 09:03:17 by dboyer            #+#    #+#              #
#    Updated: 2020/06/10 17:26:10 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    			=	pwd

SRCS    			=	ft_getcwd.c \
						pwd.c

MAIN 				= 	main.c

OBJS_MAIN 			= 	$(MAIN:.c=.o)
OBJS    			= 	$(SRCS:.c=.o)

CC      			= 	clang

RM      			= 	rm -f

LIBFT_PATH			=	../../../libs/libft
LIB_FTSTRING_PATH	=	../../../libs/libft_string

HEADERS 			=   -I ../../../libs/libft/includes \
						-I ../../../libs/libft_string/srcs/includes

CFLAGS  			= 	-Werror -Wall -Wextra -Ofast -pedantic-errors ${HEADERS}

LIBRARY	 			=	-L ../../../libs/libft -lft \
						-L ../../../libs/libft_string -lftstring

INCS				= 	pwd.h \
						../../../libs/libft_string/srcs/includes/libft_string.h

################################################################################
#									pwd make
################################################################################

%.o: %.c ${INCS}
	$(CC) $(CFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) : $(OBJS) $(OBJS_MAIN)
	make -C $(LIBFT_PATH)
	make -C $(LIB_FTSTRING_PATH)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_MAIN} ${LIBRARY}

clean   :
	make clean -C $(LIBFT_PATH)
	make clean -C $(LIB_FTSTRING_PATH)
	$(RM) $(OBJS)
	$(RM) ${OBJS_MAIN}

fclean  : clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(LIB_FTSTRING_PATH)
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
