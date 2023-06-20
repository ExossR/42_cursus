/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:29:58 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/16 19:20:58 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	line_is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] != '\t' && str[i] != '\n' && str[i] != '\v'
			&& str[i] != '\f' && str[i] != '\r' && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	init_sign(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}

void	init_termios(void)
{
	struct termios	tty;

	tcgetattr(STDIN_FILENO, &tty);
	tty.c_lflag &= ~ECHOCTL;
	tty.c_cc[VQUIT] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

void	upgrade_sh_lvl(void)
{
	int		pos;
	char	*tmp;
	char	*res;

	pos = search_in_env(g_struct->g_env, "SHLVL=");
	if (pos != -1)
	{
		tmp = ft_itoa(ft_atoi(&g_struct->g_env[pos][6]) + 1);
		res = ft_strjoin("SHLVL=", tmp);
		free(tmp);
		tmp = g_struct->g_env[pos];
		g_struct->g_env[pos] = res;
		free(tmp);
	}
}

void	alloc_global(char **env)
{
	g_struct = malloc(sizeof(t_struct));
	g_struct->value_of_return = 0;
	g_struct->is_in_cmd = false;
	g_struct->g_env = get_tot_env(env);
	g_struct->pid_here_doc = 0;
	g_struct->is_in_here_doc = false;
	upgrade_sh_lvl();
	init_sign();
	init_termios();
}
