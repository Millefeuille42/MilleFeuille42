######### Commons #########

SRCS	=	AMateria.cpp	\
	Character.cpp	\
	Cure.cpp	\
	Ice.cpp	\
	MateriaSource.cpp	\
	main.cpp	\

HEAD	=	AMateria.hpp	\
	Character.hpp	\
	Cure.hpp	\
	ICharacter.hpp	\
	IMateriaSource.hpp	\
	Ice.hpp	\
	MateriaSource.hpp	\

OBJS	=	${SRCS:.cpp=.o}

NAME	=	interfaces

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
