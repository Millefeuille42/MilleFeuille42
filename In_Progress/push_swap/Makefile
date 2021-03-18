######### Commons #########

COMMONS_SRCS	=	../../In_Progress/push_swap/commons/utils/ft_atoi.c				\
                   	../../In_Progress/push_swap/commons/utils/ft_strncmp.c			\
                   	../../In_Progress/push_swap/commons/utils/ft_isdigit.c			\
                   	../../In_Progress/push_swap/commons/utils/ft_is_string_digit.c	\
                   	../../In_Progress/push_swap/commons/gnl/gnl.c					\
                   	../../In_Progress/push_swap/commons/gnl/gnl_utils.c				\
                   	../../In_Progress/push_swap/commons/stack/stack.c				\
                   	../../In_Progress/push_swap/commons/stack/swap.c				\
                   	../../In_Progress/push_swap/commons/stack/push.c				\
                   	../../In_Progress/push_swap/commons/stack/rotate.c				\
                   	../../In_Progress/push_swap/commons/stack/reverse_rotate.c		\
                   	../../In_Progress/push_swap/commons/utils/safe_free.c			\
                   	../../In_Progress/push_swap/commons/stack/actions.c				\
                   	../../In_Progress/push_swap/commons/utils/print_error.c			\

COMMONS_HEAD	=	./commons/includes/commons.h

COMMONS_INCL	=	-I ./commons/includes/


######### Checker #########

CHECKER_SRCS	=	./f_checker/main.c ${COMMONS_SRCS}

CHECKER_OBJS	=	${CHECKER_SRCS:.c=.o}

CHECKER_NAME	=	checker


######### Checker #########

PSHSWAP_SRCS	=	./f_push_swap/main.c ${COMMONS_SRCS}

PSHSWAP_OBJS	=	${PSHSWAP_SRCS:.c=.o}

PSHSWAP_NAME	=	push_swap


######### Globals #########

COMPILE	=	clang
FLAGS	=	-Wall -Wextra -Werror
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
