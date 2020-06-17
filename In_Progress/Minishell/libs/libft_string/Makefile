# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 18:42:28 by dboyer            #+#    #+#              #
#    Updated: 2020/05/12 22:03:48 by mlabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftstring.a

STRING_METHOD = srcs/string/ft_string.c\
				srcs/string/ft_clear_string.c\
				srcs/string/ft_push_string.c\
				srcs/string/ft_string_up.c\
				srcs/string/ft_prepend.c\
				srcs/string/ft_string_low.c\
				srcs/string/ft_delete.c\
				srcs/string/ft_replace.c\

SRCS 	=		srcs/functions/ft_parse.c\
            	srcs/functions/ft_move_until.c\
            	srcs/functions/ft_str_isequal.c\
            	srcs/functions/ft_strlen.c\
            	srcs/dependencies/ft_clear.c\
            	srcs/dependencies/ft_strncmp.c\
            	srcs/dependencies/ft_memmove.c\
            	srcs/dependencies/ft_memcpy.c\
            	srcs/dependencies/ft_strdup.c\
            	srcs/dependencies/ft_strnstr.c\
            	srcs/dependencies/ft_strlcpy.c\
                srcs/dependencies/ft_strlcat.c\
                srcs/dependencies/ft_strjoin.c\
                srcs/dependencies/ft_isupper.c\
                srcs/dependencies/ft_islower.c\
                srcs/dependencies/ft_toupper.c\
                srcs/dependencies/ft_tolower.c\

OBJS    = 	$(SRCS:.c=.o)

STRING_METHOD_OBJS = $(STRING_METHOD:.c=.o)

HEADERS =	-I ./includes/

CFLAGS  = -Werror -Wall -Wextra -Ofast ${HEADERS}

CC              = clang

RM     			= rm -f

INCS = ./includes/libft_string.h\
		./includes/string_object.h

%.o: %.c ${INCS}
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(STRING_METHOD_OBJS)
	ar rcs $(NAME) $(OBJS) $(STRING_METHOD_OBJS)

all             :       $(NAME)

clean   :
	$(RM) $(OBJS) $(STRING_METHOD_OBJS)

fclean  :       clean
	$(RM) $(NAME)

re              :       fclean all

.PHONY  : all clean fclean re
