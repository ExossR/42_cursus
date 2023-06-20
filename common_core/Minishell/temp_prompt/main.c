/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:29:58 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/16 19:21:13 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	count_dollar(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] == '$')
			j++;
		i++;
	}
	return (j);
}

char	*init_main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	alloc_global(env);
	return (0);
}

void	exec_main(char *line)
{
	t_cmd_line	*cmd_line;

	cmd_line = parsing(line);
	if (cmd_line != 0)
	{
		pipeline(cmd_line);
		free_cmd_line(cmd_line);
	}
}

int	main(int argc, char **argv, char **env)
{
	char		*line;
	int			i;
	int			nb_dollar;

	line = init_main(argc, argv, env);
	while (1)
	{
		i = 0;
		if (line)
			free(line);
		line = readline("Minishell> ");
		if (line == 0)
		{
			printf("A plus dans le bus, et pas sur Minishell!\n");
			exit(0);
		}
		if (line_is_empty(line) == false)
			add_history(line);
		nb_dollar = count_dollar(line);
		while (i++ < nb_dollar)
			line = transform_line(g_struct->g_env, line);
		if (line_is_empty(line) == false)
			exec_main(line);
	}
}
