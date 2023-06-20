/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:24:48 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/16 15:03:03 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	handle_redirect(t_squote *output, char *s)
{
	if (output->is_in == false)
	{
		add_to_tab(output);
		output->buff = ft_strcat_only_one(output->buff, s[output->i]);
		if (s[output->i + 1] == '>' || s[output->i + 1] == '<')
		{
			output->buff = ft_strcat_only_one(output->buff, s[output->i]);
			output->i++;
		}
		add_to_tab(output);
	}
	else
		output->buff = ft_strcat_only_one(output->buff, s[output->i]);
}
