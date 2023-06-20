/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:50:51 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 09:54:22 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	is_out_last(char **sp)
{
	int	i;

	i = length_of_tab(sp) - 1;
	while (i >= 0)
	{
		if (sp[i][0] == '>' && sp[i][1] == '\0')
			return (false);
		else if (sp[i][0] == '>')
			return (true);
		i--;
	}
	return (false);
}

bool	is_in_last(char **sp)
{
	int	i;

	i = length_of_tab(sp) - 1;
	while (i >= 0)
	{
		if (sp[i][0] == '<' && sp[i][1] == '\0')
			return (false);
		else if (sp[i][0] == '<')
			return (true);
		i--;
	}
	return (false);
}
