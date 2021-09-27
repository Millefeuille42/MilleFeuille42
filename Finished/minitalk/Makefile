######### Commons #########

COMMONS_SRCS    =       ./utils/ft_atoi.c		\
						./utils/ft_is_string_digit.c	\
						./utils/ft_isdigit.c	\
						./utils/ft_putnbr.c		\
						./utils/ft_putstr.c

COMMONS_INCL    =       -I ./

COMMONS_HEAD    =       ./minitalk.h

######### CLIENT #########

CLIENT_SRCS    =		${COMMONS_SRCS} ./f_client/main.c	\
						./f_client/sigs.c	\

CLIENT_HEAD    =       ${COMMONS_HEAD} ./f_client/client.h

CLIENT_OBJS    =       ${CLIENT_SRCS:.c=.o}

CLIENT_INCL    =       ${COMMONS_INCL} -I ./f_client/

CLIENT_NAME    =       client

######### SERVER #########

SERVER_SRCS    =       ${COMMONS_SRCS} ./f_server/main.c	\
                       ./f_server/sigs.c	\
                       ./f_server/stats.c	\

SERVER_HEAD    =       ${COMMONS_HEAD} ./f_server/server.h

SERVER_OBJS    =       ${SERVER_SRCS:.c=.o}

SERVER_INCL    =       ${COMMONS_INCL} -I ./f_server/

SERVER_NAME    =       server


######### Globals #########

COMPILE =       clang
FLAGS   =       -Wall -Wextra -Werror -Ofast
RM      =       rm -f


#########  Rules  #########

.c.o    :
						${COMPILE} ${FLAGS} -c $< -o $@

all             :       ${CLIENT_NAME} ${SERVER_NAME}

${CLIENT_NAME} :       ${CLIENT_OBJS} ${CLIENT_HEAD}
						${COMPILE} ${FLAGS} -o ${CLIENT_NAME} ${CLIENT_OBJS} ${CLIENT_INCL}

${SERVER_NAME} :       ${SERVER_OBJS} ${SERVER_HEAD}
						${COMPILE} ${FLAGS} -o ${SERVER_NAME} ${SERVER_OBJS} ${SERVER_INCL}

clean   :
						${RM} ${CLIENT_OBJS} ${SERVER_OBJS}

fclean  :       clean
						${RM} ${CLIENT_NAME} ${SERVER_NAME}

re              :       fclean
						make all

.PHONY  :       all clean fclean re
