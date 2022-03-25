######### Commons #########

SRCS	=			contact.cpp		\
					phoneBook.cpp

HEAD	=	        contact.hpp		\
					phoneBook.hpp

INCL	=	-I ./

OBJS	=	${SRCS:.cpp=.o}

NAME	=	PhoneBook

COMPILE	=	clang++
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f


#########  Rules  #########

.c.o	:
			${COMPILE} ${FLAGS} ${INCL} -c $< -o $@

all		:	${NAME}

${NAME} :	${OBJS} ${HEAD}
			${COMPILE} ${FLAGS} -o ${NAME} ${OBJS} ${INCL}

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
