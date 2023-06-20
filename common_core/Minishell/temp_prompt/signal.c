/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:38:37 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/16 19:22:13 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	set_termios(bool in_cmd)
{
	struct termios	tty;

	tcgetattr(STDIN_FILENO, &tty);
	if (in_cmd == true)
	{
		tty.c_lflag |= ECHOCTL;
		tty.c_cc[VQUIT] = 034;
	}
	else
	{
		tty.c_lflag &= ~ECHOCTL;
		tty.c_cc[VQUIT] = 0;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

void	handle_sigint(int signum)
{
	(void) signum;
	g_struct->value_of_return = 1;
	if (g_struct->is_in_cmd == true)
	{
		g_struct->value_of_return = 130;
		if (g_struct->is_in_here_doc == true)
		{
			g_struct->value_of_return = 1;
			kill(g_struct->pid_here_doc, SIGINT);
			exit(0);
		}
	}
	if (g_struct->is_in_here_doc == false)
		printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	if (g_struct->is_in_here_doc == true || g_struct->is_in_cmd == false)
		rl_redisplay();
}

void	handle_sigquit(int signum)
{
	(void) signum;
	ft_putstr_fd("Quit: 3\n", 1);
	g_struct->value_of_return = 131;
}
