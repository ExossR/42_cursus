/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:29:37 by asahonet          #+#    #+#             */
/*   Updated: 2023/03/02 17:12:39 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo			*philo;
	t_gen_philo		*inf_gen;

	philo = 0;
	inf_gen = 0;
	if (!(argc == 5 || argc == 6)
		|| (parsing_args(argv) == 1 && verif_vals(argv) == 1))
		return (1);
	if (init_struct(&philo, &inf_gen, argc, argv) != 0)
		return (free_philo(philo, inf_gen));
	if (init_thread(&philo, inf_gen) != 0)
		return (free_philo(philo, inf_gen));
	pthread_mutex_lock(&inf_gen->philo);
	if (inf_gen->nb_times_philo_eats != -1)
		usleep(250000);
	pthread_mutex_unlock(&inf_gen->philo);
	free_philo(philo, inf_gen);
	return (0);
}
