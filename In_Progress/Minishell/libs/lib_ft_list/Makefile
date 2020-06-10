# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 18:42:28 by dboyer            #+#    #+#              #
#    Updated: 2020/05/12 16:19:53 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftlist.a

SRCS 	=	srcs/ft_add_back.c\
		srcs/ft_clear.c\
		srcs/ft_concat.c\
		srcs/ft_del.c\
		srcs/ft_list_copy.c\
		srcs/ft_list_iter.c\
		srcs/ft_list.c\
		srcs/ft_new_element.c\
		srcs/ft_get_list_element.c\
		srcs/ft_search.c\
		srcs/ft_insert_before.c\

OBJS    =       $(SRCS:.c=.o)
HEADERS = -I ./includes/

CFLAGS  = -Werror -Wall -Wextra -O3 ${HEADERS} 

CC              = clang

RM      =       rm -f

INCS = ./includes/ft_list.h

%.o: %.c ${INCS}
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS) 

all             :       $(NAME)

clean   :
	$(RM) $(OBJS)

fclean  :       clean
	$(RM) $(NAME)

re              :       fclean all

.PHONY  : all clean fclean re
