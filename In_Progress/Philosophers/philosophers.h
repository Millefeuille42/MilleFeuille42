//
// Created by millefeuille on 2/12/21.
//

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_fork {
	int				id;
	pthread_mutex_t mutex;
	char			last;
}					t_fork;

typedef struct		s_philo {
	int				id;
	t_fork			*forks[2];
	char			last;
}					t_philo;

typedef struct		s_app {
	int				philo_num;
	t_philo			*philos;
	t_fork			*forks;
}					t_app;

#endif
