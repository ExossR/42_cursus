/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:38:43 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/15 12:30:31 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	double_check(char *a, char *b)
{
	if (ft_strncmp(a, b, ft_strlen(b)) == 0)
	{
		if (ft_strncmp(a, b, ft_strlen(a)) == 0)
			return (true);
	}
	return (false);
}

void	builtins_switch(char *name, t_cmd cmd)
{
	if (double_check(name, "echo") == true)
		echo(cmd);
	else if (double_check(name, "cd") == true)
		cd(cmd);
	else if (double_check(name, "pwd") == true)
		pwd(cmd);
	else if (double_check(name, "export") == true)
		ft_export(cmd);
	else if (double_check(name, "exit") == true)
		ft_exit(cmd);
	else if (double_check(name, "unset") == true)
		unset(cmd);
	else if (double_check(name, "env") == true)
		env(cmd);
}
