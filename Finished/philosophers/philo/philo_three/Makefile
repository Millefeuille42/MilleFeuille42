######### Commons #########

SRCS	=			main.c					\
					args.c \
					ft_atoi.c \
					init_app.c \
					philo.c \
					philo_actions.c \
					philo_setup.c \
					philo_take_fork.c \
					philo_utils.c \
					timeval_to_ms.c \

HEAD	=	        philo_three.h

INCL	=	-I ./

OBJS	=	${SRCS:.c=.o}

NAME	=	philo_three

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
