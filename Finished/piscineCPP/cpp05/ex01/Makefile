######### Commons #########

SRCS	=	Bureaucrat.cpp	\
	Form.cpp	\
	main.cpp	\

HEAD	=	Bureaucrat.hpp	\
	Form.hpp	\

OBJS	=	${SRCS:.cpp=.o}

NAME	=	bureau

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
