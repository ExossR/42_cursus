/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:12:06 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/02 16:51:38 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_watcher(pthread_mutex_t *m)
{
	pthread_mutex_destroy(m);
	free(m);
}

void	mutex_destroy(t_gen_philo *ginf)
{
	pthread_mutex_destroy(&ginf->sleep_p);
	pthread_mutex_destroy(&ginf->think_p);
	pthread_mutex_destroy(&ginf->sleep_p);
	pthread_mutex_destroy(&ginf->think_p);
	pthread_mutex_destroy(&ginf->prep);
	pthread_mutex_destroy(&ginf->dead);
	pthread_mutex_destroy(&ginf->eat);
	pthread_mutex_destroy(&ginf->nbeat);
	pthread_mutex_destroy(&ginf->philo);
}

int	free_philo(t_philo *p, t_gen_philo *ginf)
{
	int	i;
	int	n;

	i = 0;
	n = ginf->nb_philo;
	if (ginf)
	{
		if (ginf->mutex)
		{
			while (i < n)
				pthread_mutex_destroy(&ginf->mutex[i++]);
			free(ginf->mutex);
		}
		mutex_destroy(ginf);
		free(ginf);
	}
	if (p)
		free(p);
	return (1);
}
