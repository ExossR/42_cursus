/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:27:16 by asahonet          #+#    #+#             */
/*   Updated: 2023/01/04 19:22:31 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>

/*--------------ft_split.c--------------*/
char	**ft_split(char *s, char c);

/*--------------main_utils.c--------------*/
char	*find_path_cmd(char **env, char *cmd);
int		verif_arg(int argc, char **argv);

/*--------------main_utils_2.c--------------*/
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif