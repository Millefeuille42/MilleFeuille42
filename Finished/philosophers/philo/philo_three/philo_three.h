/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:23:51 by mlabouri          #+#    #+#             */
/*   Updated: 2021/04/20 13:23:51 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef enum		e_bool {
	false,
	true
}					t_bool;

typedef enum		e_state {
	THINK,
	FORK,
	EAT,
	SLEEP,
	DIED,
	STOP
}					t_state;

typedef struct		s_param {
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_eat;
}					t_param;

typedef struct		s_philo
{
	int				id;
	int				n_fork;
	int				forks_taken;
	int				n_eat;
	int				time_limits[6];
	struct timeval	current_time;
	t_bool			*alive;
	t_state			state;
	pid_t			process_id;
	sem_t			*sem_forks;
	sem_t			*sem_output;
}					t_philo;

typedef struct		s_app
{
	int				n;
	t_bool			alive;
	t_philo			*philosophers;
	sem_t			*sem_forks;
	sem_t			*sem_output;
	char			proper_init;
}					t_app;

typedef void		(*t_actions)(t_philo *philo);

long				timeval_to_ms(struct timeval *time);
t_bool				ft_isnum(const char *str);
t_bool				check_args(int argc, const char **argv);
t_param				parse_args(int argc, const char **argv);
t_philo				philo_setup(const t_param *args, int id, sem_t *forks);
t_app				init_app(int argc, const char **argv);
void				philo_thread(t_philo *philo, t_app *app);
void				philo_think(t_philo *philo);
void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				philo_take_forks(t_philo *philo);
void				philo_speak(t_philo *philo, char *message);
void				philo_wait(int time);
void				philo_finish(t_philo *philo, t_state state);
void				delete_app(t_app *app);
int					get_timestamp(t_philo *philo);
int					ft_atoi(const char *str);
#endif
