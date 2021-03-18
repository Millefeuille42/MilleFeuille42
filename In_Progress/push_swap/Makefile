######### Commons #########

COMMONS_SRCS	=	./commons/utils/ft_atoi.c				\
                    ./commons/utils/ft_strncmp.c			\
                    ./commons/utils/ft_itoa.c				\
                    ./commons/utils/ft_isdigit.c			\
                    ./commons/utils/ft_is_string_digit.c	\
                    ./commons/gnl/gnl.c						\
                    ./commons/gnl/gnl_utils.c				\
                    ./commons/stack/stack.c					\
                    ./commons/stack/swap.c					\
                    ./commons/stack/push.c					\
                    ./commons/stack/rotate.c				\
                    ./commons/stack/reverse_rotate.c		\
                    ./commons/utils/safe_free.c				\
                    ./commons/stack/actions.c				\
                    ./commons/utils/print_error.c			\

COMMONS_OBJS	=	${COMMONS_SRCS:.c=.o}

COMMONS_HEAD	=	./commons/includes/commons.h

COMMONS_INCL	=	-I ./commons/includes/


######### Checker #########

CHECKER_SRCS	=	./f_checker/main.c

CHECKER_OBJS	=	${CHECKER_SRCS:.c=.o}

CHECKER_NAME	=	checker


######### Checker #########

PSHSWAP_SRCS	=	./f_push_swap/main.c

PSHSWAP_OBJS	=	${PSHSWAP_SRCS:.c=.o}

PSHSWAP_NAME	=	push_swap


######### Globals #########

COMPILE	=	clang
FLAGS	=	-Ofast
A_FLAGS =	-Wall -Wextra -Werror
RM		=	rm -f


#########  Rules  #########

.c.o	:
			${COMPILE} ${FLAGS} ${COMMONS_INCL} -c $< -o $@

all		:	${CHECKER_NAME} ${PSHSWAP_NAME}

${CHECKER_NAME} :	${CHECKER_OBJS} ${COMMONS_OBJS} ${COMMONS_HEAD}
			${COMPILE} ${FLAGS} -o ${CHECKER_NAME} ${CHECKER_OBJS} ${COMMONS_OBJS} ${COMMONS_INCL}

${PSHSWAP_NAME} :	${PSHSWAP_OBJS} ${COMMONS_OBJS} ${COMMONS_HEAD}
			${COMPILE} ${FLAGS} -o ${PSHSWAP_NAME} ${PSHSWAP_OBJS} ${COMMONS_OBJS} ${COMMONS_INCL}

clean	:
			${RM} ${CHECKER_OBJS} ${COMMONS_OBJS} ${PSHSWAP_OBJS}

fclean	:	clean
			${RM} ${CHECKER_NAME} ${PSHSWAP_NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
