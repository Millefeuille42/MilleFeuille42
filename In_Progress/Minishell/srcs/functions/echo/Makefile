NAME    			=	echo

SRCS    			=	./echo.c

LIBFT_PATH			= 	"../../../libs/libft/"

OBJS    			= 	$(SRCS:.c=.o)

LIBRARY	 			=	-L ../../../libs/libft -lft

CC      			= 	clang

RM      			= 	rm -f

HEADERS 			= 	-I ./ \
						-I ../../../libs/libft/includes

CFLAGS  			= 	-Werror -Wall -Wextra -Ofast -pedantic-errors ${HEADERS}

INCS				=	../../../libs/libft/includes/libft.h \
						./echo.h

################################################################################
#									echo make
################################################################################

%.o: %.c ${INCS}
	$(CC) $(CFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) : $(OBJS) $(OBJS_MAIN)
	make -C $(LIBFT_PATH)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBRARY}

clean   :
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean  : clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

run 	: all
	./${NAME}

re      : fclean all

################################################################################
#												Extra make
################################################################################

norm: fclean
	~/.norminette/norminette.rb

.PHONY  :	all clean fclean re bonus%
