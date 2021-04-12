######### Commons #########

COMMONS_SRCS	=	./commons/utils/ft_atoi.c				\
                   	./commons/utils/ft_strncmp.c			\
                   	./commons/utils/ft_isdigit.c			\
                   	./commons/utils/ft_is_string_digit.c	\
                   	./commons/gnl/gnl.c					\
                   	./commons/gnl/gnl_utils.c				\
                   	./commons/stack/stack.c				\
                   	./commons/stack/swap.c				\
                   	./commons/stack/push.c				\
                   	./commons/stack/rotate.c				\
                   	./commons/stack/reverse_rotate.c		\
                   	./commons/utils/safe_free.c			\
                   	./commons/stack/actions.c				\
                   	./commons/utils/print_error.c			\

COMMONS_HEAD	=	./commons/includes/commons.h

COMMONS_INCL	=	-I ./commons/includes/


######### Checker #########

CHECKER_SRCS	=	./f_checker/main.c ${COMMONS_SRCS}

CHECKER_HEAD	=	${COMMONS_HEAD}

CHECKER_OBJS	=	${CHECKER_SRCS:.c=.o}

CHECKER_INCL	=	${COMMONS_INCL}

CHECKER_NAME	=	checker

######### PUSH_SWAP #########

PSHSWAP_SRCS	=	./f_push_swap/main.c \
					./f_push_swap/selection_sort.c \
					./f_push_swap/insertion_sort.c \
					./f_push_swap/insertion_sort_get_actions.c \
					./f_push_swap/sort_utils.c ${COMMONS_SRCS}

PSHSWAP_HEAD	=	./f_push_swap/push_swap.h ${COMMONS_HEAD}

PSHSWAP_OBJS	=	${PSHSWAP_SRCS:.c=.o}

PSHSWAP_INCL	=	-I ./f_push_swap/includes/ ${COMMONS_INCL}

PSHSWAP_NAME	=	push_swap


######### Globals #########

COMPILE	=	clang
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f


#########  Rules  #########

.c.o	:
			${COMPILE} ${FLAGS} -c $< -o $@

all		:	${CHECKER_NAME} ${PSHSWAP_NAME}

${CHECKER_NAME} :	${CHECKER_OBJS} ${CHECKER_HEAD}
			${COMPILE} ${FLAGS} -o ${CHECKER_NAME} ${CHECKER_OBJS} ${CHECKER_INCL}

${PSHSWAP_NAME} :	${PSHSWAP_OBJS} ${PSHSWAP_HEAD}
			${COMPILE} ${FLAGS} -o ${PSHSWAP_NAME} ${PSHSWAP_OBJS} ${PSHSWAP_INCL}

clean	:
			${RM} ${CHECKER_OBJS} ${PSHSWAP_OBJS}

fclean	:	clean
			${RM} ${CHECKER_NAME} ${PSHSWAP_NAME}

re		:	fclean
			make all -j

test	:	re
			pushSwapTester ./${PSHSWAP_NAME} ./${CHECKER_NAME} validity average

.PHONY	:	all clean fclean re
