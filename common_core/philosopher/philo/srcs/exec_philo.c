/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:03:52 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/02 18:15:56 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	unlock_mutexes(t_philo *p)
{
	if (p->num_philo + 1 != p->nb_philo)
		pthread_mutex_unlock(&p->inf_gen->mutex[p->num_philo + 1]);
	else
		pthread_mutex_unlock(&p->inf_gen->mutex[0]);
	pthread_mutex_unlock(&p->inf_gen->mutex[p->num_philo]);
}

int	lock_mutexes(t_philo *p, long long timeset)
{
	pthread_mutex_lock(&p->inf_gen->mutex[p->num_philo]);
	if (verif_dead(p) == 1)
	{
		pthread_mutex_unlock(&p->inf_gen->mutex[p->num_philo]);
		return (1);
	}
	printf("%lld %d has taken a fork\n",
		get_time_millisec() - timeset, p->num_philo);
	if (p->num_philo + 1 != p->nb_philo)
		pthread_mutex_lock(&p->inf_gen->mutex[p->num_philo + 1]);
	else
		pthread_mutex_lock(&p->inf_gen->mutex[0]);
	if (verif_dead(p) == 1)
	{
		unlock_mutexes(p);
		return (1);
	}
	printf("%lld %d has taken a fork\n",
		get_time_millisec() - timeset, p->num_philo);
	return (0);
}

void	is_eating(t_philo *p, long long timeset)
{
	int	time_eat;

	time_eat = 0;
	if (lock_mutexes(p, timeset) != 0)
		return ;
	p->last_eat = get_time_millisec();
	p->nbeats++;
	printf("%lld %d is eating\n",
		get_time_millisec() - timeset, p->num_philo);
	pthread_mutex_lock(&p->inf_gen->eat);
	time_eat = p->inf_gen->time_eat;
	pthread_mutex_unlock(&p->inf_gen->eat);
	usleep_debug(time_eat);
	unlock_mutexes(p);
}

void	is_sleeping(t_philo *p, long long timeset)
{
	int	time_sleep;

	time_sleep = 0;
	pthread_mutex_lock(&p->inf_gen->sleep_p);
	if (verif_dead(p) == 1)
	{
		pthread_mutex_unlock(&p->inf_gen->sleep_p);
		return ;
	}
	printf("%lld %d is sleeping\n",
		get_time_millisec() - timeset, p->num_philo);
	time_sleep = p->inf_gen->time_sleep;
	pthread_mutex_unlock(&p->inf_gen->sleep_p);
	usleep_debug(time_sleep);
}

void	is_thinking(t_philo *p, long long timeset)
{
	pthread_mutex_lock(&p->inf_gen->think_p);
	if (verif_dead(p) == 1)
	{
		pthread_mutex_unlock(&p->inf_gen->think_p);
		return ;
	}
	printf("%lld %d is thinking\n",
		get_time_millisec() - timeset, p->num_philo);
	pthread_mutex_unlock(&p->inf_gen->think_p);
}
