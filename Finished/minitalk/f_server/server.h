//
// Created by Millefeuille on 21/06/2021.
//

#ifndef SERVER_H
# define SERVER_H

# include "../minitalk.h"

void			setup(void);

char			message_start_stop(void);

char			*get_status(void);
char			*get_last(void);
unsigned char	*get_mess(void);

#endif
