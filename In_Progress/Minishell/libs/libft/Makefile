# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 18:42:28 by dboyer            #+#    #+#              #
#    Updated: 2020/05/08 17:31:44 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
 
SRCS 	=	srcs/ft_atoi.c\
			srcs/ft_isalpha.c\
			srcs/ft_isdigit.c\
			srcs/ft_isalnum.c\
			srcs/ft_isascii.c\
			srcs/ft_isprint.c\
			srcs/ft_islower.c\
			srcs/ft_isupper.c\
			srcs/ft_toupper.c\
			srcs/ft_str_toupper.c\
			srcs/ft_str_tolower.c\
			srcs/ft_tolower.c\
			srcs/ft_strncmp.c\
			srcs/ft_memcmp.c \
			srcs/ft_strlen.c\
			srcs/ft_strlcpy.c\
			srcs/ft_strlcat.c\
			srcs/ft_strchr.c\
			srcs/ft_strnstr.c\
			srcs/ft_strdup.c\
			srcs/ft_memset.c\
			srcs/ft_memmove.c\
			srcs/ft_bzero.c\
			srcs/ft_memchr.c\
			srcs/ft_calloc.c\
			srcs/ft_memcpy.c\
			srcs/ft_substr.c\
			srcs/ft_strjoin.c\
			srcs/ft_strtrim.c\
			srcs/ft_cinset.c\
			srcs/ft_split.c\
			srcs/ft_split_clean.c\
			srcs/ft_itoa.c\
			srcs/ft_strmapi.c\
			srcs/ft_putchar_fd.c\
			srcs/ft_putstr_fd.c\
			srcs/ft_isspace.c\
			srcs/ft_strrchr.c\
			srcs/ft_putendl_fd.c\
			srcs/ft_putnbr_fd.c\
			srcs/ft_memccpy.c\
			srcs/ft_putchar.c\
			srcs/ft_putstr.c\
			srcs/ft_isflag.c\
			srcs/ft_getflag.c\
			srcs/ft_putnbr_unsigned.c\
			srcs/ft_format.c\
			srcs/ft_minmax_nb.c\
			srcs/ft_minmax.c\
			srcs/ft_print_char.c\
			srcs/ft_print_str.c\
			srcs/ft_print_nb.c\
			srcs/ft_print_unsigned_nb.c\
			srcs/ft_putnstr.c\
			srcs/ft_nbrlen.c\
			srcs/ft_nbrlen_base.c\
			srcs/ft_nbrlen_unsigned.c\
			srcs/ft_abs.c\
			srcs/ft_parsing.c\
			srcs/ft_minmax_unsigned_nb.c\
			srcs/ft_putnbr_hex.c\
			srcs/ft_strrev.c\
			srcs/ft_minmax_nb_hex.c\
			srcs/ft_print_nb_hex.c\
			srcs/ft_print_memory.c\
			srcs/ft_minmax_memory.c\
			srcs/ft_print.c\
			srcs/ft_minmax_str.c\
			srcs/ft_printf.c\
			srcs/ft_print_percent.c\
			srcs/ft_print_space_before.c\
			srcs/ft_print_space_after.c\
			srcs/ft_print_zero_padding.c\
			srcs/get_next_line.c\

OBJS 	=	$(SRCS:.c=.o)

HEADERS = -I ./includes/

CFLAGS 	= -Werror -Wall -Wextra -O3 ${HEADERS}

CC 		= clang

CLEAN = clean

RM	=	rm -f

INCS = ./includes/libft.h

%.o: %.c ${INCS}
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
		ar rc $(NAME) $(OBJS)

all		:	$(NAME)

clean	:
		$(RM) $(OBJS) $(BON_OBJS)

fclean	:	clean
		$(RM) $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re bonus
