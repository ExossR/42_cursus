/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:02:57 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/02 17:05:51 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_gen_philo
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_times_philo_eats;
	int				one_died;
	long long		timeset;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	sleep_p;
	pthread_mutex_t	think_p;
	pthread_mutex_t	prep;
	pthread_mutex_t	dead;
	pthread_mutex_t	eat;
	pthread_mutex_t	nbeat;
	pthread_mutex_t	philo;
}	t_gen_philo;

typedef struct s_philo
{
	int				nb_philo;
	int				num_philo;
	int				nbeats;
	long long		last_eat;
	t_gen_philo		*inf_gen;
}	t_philo;

int			ft_atoi(const char *nptr);
int			parsing_args(char **argv);
int			verif_vals(char **argv);
long long	get_time_millisec(void);
void		usleep_debug(int time_to_eat);
int			init_struct(t_philo **p,
				t_gen_philo **ginf, int argc, char **argv);
int			init_thread(t_philo **p, t_gen_philo *ginf);
void		is_eating(t_philo *p, long long timeset);
void		is_sleeping(t_philo *p, long long timeset);
void		is_thinking(t_philo *p, long long timeset);
void		*execs_p(void *p);
void		thread_create(t_philo *p, pthread_t *th, int n);
void		free_watcher(pthread_mutex_t *m);
int			free_philo(t_philo *p, t_gen_philo *ginf);
int			verif_dead(t_philo *p);
int			verif_eat(t_philo *p);
long long	assign_timeset(t_philo *p);
int			assign_nbeats(t_philo *p);

#endif
