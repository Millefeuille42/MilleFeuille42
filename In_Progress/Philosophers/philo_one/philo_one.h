//
// Created by millefeuille on 2/22/21.
//

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <fcntl.h>

enum			e_params {
	philo_num,
	tt_die,
	tt_eat,
	tt_sleep,
	ts_eat
};

enum			e_status {
	thinking,
	eating,
	sleeping,
	ded
};

typedef struct		s_fork {
	char			status;
	char			last;
	int				id;
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct 		s_philo {
	char			last;
	char            promise;
	int				id;
	int				status;
	int				time_ate;
	pthread_t		thread_id;
	pthread_mutex_t	*speak_mutex;
	pthread_mutex_t	*death_mutex;
	t_fork			*forks[2];
}					t_philo;

typedef struct		s_params {
    int				conf[5];
	unsigned long			st_time;
	char			*stop;
	t_philo			*philo;
}					t_params;

typedef struct		s_app {
	int				params[5];
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	speak_mutex;
	t_fork			*forks;
	t_philo			*philos;
}					t_app;

typedef char		(*t_c_func)(t_params *);
typedef void		(*t_p_func)(t_params *);

typedef struct		s_do_params {
	t_params		*params;
	t_p_func		func;
}					t_do_params;

int					ft_atoi(const char *str);
int					a_malloc(void **ptr, size_t size);

void				ft_milli_sleep(unsigned long time);
void				ft_milli_sleep_interrupt(unsigned long time, const char *interrupt);
unsigned long		time_to_milli(struct timeval time);
unsigned long		get_cur_time();
unsigned long		get_time_since(unsigned long tm);

void				destroy_forks(t_app *app);
int					init_forks(t_app *app);
t_fork				*get_fork_by_id(t_app *app, int id);

char				philo_eat(t_params *params);
char				philo_sleep(t_params *params);
void				philo_take_fork(t_params *params);
char				philo_put_fork(t_params *params);
char				philo_think(t_params *params);
void				philo_speak(t_params *params, char *message);
void				philo_start(t_app *app);
char philo_do_promise(t_params *params);
int					init_philos(t_app *app);

#endif //PHILO_ONE_H
