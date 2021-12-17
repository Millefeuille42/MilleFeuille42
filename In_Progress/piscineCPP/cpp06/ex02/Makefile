######### Commons #########

SRCS	=	A.cpp	\
	B.cpp	\
	Base.cpp	\
	C.cpp	\
	main.cpp	\

HEAD	=	A.hpp	\
	B.hpp	\
	Base.hpp	\
	C.hpp	\

OBJS	=	${SRCS:.cpp=.o}

NAME	=	ex02

COMPILE	=	c++

FLAGS	=	-Wall -Wextra -Werror -pedantic -std=c++98

RM	=	rm -f


#########  Rules  #########


.cpp.o	:
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
