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
