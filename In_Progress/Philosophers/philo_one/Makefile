######### Commons #########

SRCS	=			main.c					\
                    utils/ft_atoi.c		\
                    utils/ft_milli_sleep.c	\
                    utils/a_malloc.c		\
                    utils/get_time_since.c	\
                    utils/time_to_milli.c	\
                    forks/forks.c			\
                    philos/philos.c		\
                    philos/philos_utils.c	\
                    philos/philos_func.c

HEAD	=	        philo_one.h

INCL	=	-I ./

OBJS	=	${SRCS:.c=.o}

NAME	=	philo_one

COMPILE	=	clang
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f


#########  Rules  #########

.c.o	:
			${COMPILE} ${FLAGS} ${INCL} -c $< -o $@

all		:	${NAME}

${NAME} :	${OBJS} ${HEAD}
			${COMPILE} ${FLAGS} -o ${NAME} ${OBJS} ${INCL} -lpthread

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
