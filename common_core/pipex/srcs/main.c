/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:25:25 by asahonet          #+#    #+#             */
/*   Updated: 2023/01/04 19:54:33 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_son(char **argv, char **env, int pipe_fd[2])
{
	int		fd;
	char	*path_cmd;

	close(pipe_fd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	if (dup2(fd, 0) == -1 || dup2(pipe_fd[1], 1) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	path_cmd = find_path_cmd(env, argv[2]);
	if (execve(path_cmd, ft_split(argv[2], ' '), env) == -1)
	{
		write(2, "pipex: Command not found\n", 25);
		exit(0);
	}
}

void	process_father(char **argv, char **env, int pipe_fd[2], int status)
{
	int		fd;
	char	*path_cmd;

	wait(&status);
	close(pipe_fd[1]);
	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 00755);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_fd[0], 0) == -1 || dup2(fd, 1) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	path_cmd = find_path_cmd(env, argv[3]);
	if (execve(path_cmd, ft_split(argv[3], ' '), env) == -1)
	{
		write(2, "pipex: Command not found\n", 25);
		exit(0);
	}
}

int	main(int argc, char **argv, char **env)
{
	pid_t	f_pid;
	pid_t	s_pid;
	int		pipe_fd[2];
	int		status;

	status = 0;
	if (verif_arg(argc, argv) == 1)
		return (1);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	s_pid = fork();
	if (s_pid == -1)
		return (1);
	else if (s_pid == 0)
		process_son(argv, env, pipe_fd);
	f_pid = fork();
	if (f_pid == -1)
		return (1);
	else if (f_pid == 0)
		process_father(argv, env, pipe_fd, status);
	waitpid(-1, &status, 0);
	return (0);
}
