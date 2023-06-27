/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tower.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:14:06 by lfresnay          #+#    #+#             */
/*   Updated: 2022/09/25 16:26:32 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOWER_H
# define TOWER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_valeur
{
	int	up[4];
	int	down[4];
	int	left[4];
	int	right[4];
}	t_valeur;

int		***initialize(int all[4][24][4], int ***valid, t_valeur coeff);

void	solve_map(int ***valid, t_valeur coeff);

void	init_tries(int tab[24][4]);

int		check_line(int line[4], t_valeur coeff, int id);

int		check_reverse_line(int line[4], t_valeur coeff, int id);

int		check_column(int column[4][4], t_valeur coeff, int id);

int		check_reverse_column(int column[4][4], t_valeur coeff, int id);

#endif
