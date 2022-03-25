######### Commons #########

SRCS	=	Animal.cpp	\
	Cat.cpp	\
	Dog.cpp	\
	WrongAnimal.cpp	\
	WrongCat.cpp	\
	main.cpp	\

HEAD	=	Animal.hpp	\
	Cat.hpp	\
	Dog.hpp	\
	WrongAnimal.hpp	\
	WrongCat.hpp	\

OBJS	=	${SRCS:.cpp=.o}

NAME	=	animals

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
