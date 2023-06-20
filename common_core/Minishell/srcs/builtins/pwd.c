/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:58:17 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 09:30:21 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	pwd(t_cmd cmd)
{
	char	buff[PATH_MAX];

	(void) cmd;
	if (getcwd(buff, PATH_MAX) == 0)
	{
		call_error();
		exit(1);
	}
	ft_putstr_fd(buff, 1);
	ft_putstr_fd("\n", 1);
	exit(0);
	return (0);
}
