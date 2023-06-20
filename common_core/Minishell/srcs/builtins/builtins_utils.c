/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:09:57 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 19:17:17 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	call_error(void)
{
	g_struct->value_of_return = errno;
	perror(0);
	return (errno);
}

t_cmd	*init_t_cmd(void)
{
	t_cmd	*output;

	output = malloc(sizeof(t_cmd));
	output->name = 0;
	output->args = 0;
	output->redirect_out = 0;
	output->redirect_in = 0;
	output->here_doc = 0;
	output->redirect_append = 0;
	output->is_pipe_in = false;
	output->is_pipe_out = false;
	output->out_last = false;
	output->in_last = false;
	return (output);
}

char	*tf_split(char **tab)
{
	int		i;
	int		size;
	char	*output;

	size = 0;
	i = 0;
	while (tab[i] != 0)
		size += ft_strlen(tab[i++]);
	output = malloc (sizeof(char) * (size + 1) + (12 * (i + 1)));
	output[0] = '\0';
	i = 0;
	while (tab[i] != 0)
	{
		ft_strlcat(output, "declare -x ", 4294967295);
		ft_strlcat(output, tab[i++], 4294967295);
		ft_strlcat(output, "\n", 4294967295);
	}
	return (output);
}
