######### Commons #########

SRCS	=	Fixed.cpp	\
	main.cpp	\

HEAD	=	Fixed.hpp	\

OBJS	=	${SRCS:.cpp=.o}

NAME	=	fixed

COMPILE	=	clang++

FLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f


#########  Rules  #########


.c.o	:
			${COMPILE} ${FLAGS} -c $< -o $@

all		:	${NAME}

${NAME} :	${OBJS}
			${COMPILE} ${FLAGS} -o ${NAME} ${OBJS}

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
