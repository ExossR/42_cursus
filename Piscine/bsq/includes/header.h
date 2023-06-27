/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeyre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:59:18 by aribeyre          #+#    #+#             */
/*   Updated: 2022/10/06 10:41:35 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libgen.h>
# include <stdlib.h>

typedef struct s_squares
{
	int		posx;
	int		posy;
	int		size;
	int		boardx;
	int		boardy;
}	t_square;

int		solve_puzzle(char *filename);
char	**ft_board(char *filename, t_square *next);
void	ft_solve_board(char **board, char *disp, t_square *big, t_square *next);
int		ft_square_cmp(t_square *next, t_square *biggest);
void	display_solution(char **board, t_square *b, char *display);
int		ft_strlen(char *str);
void	ft_strcat_but_only_one(char *dest, char src);
int		ft_verif_parsing(char *path, int nbline);
char	**ft_firstline(char *buf, int sizefl, int i, int j);
int		ft_nbline_to_int(char *str);
int		size_firstline(char *path);
int		size_line(char *path);
void	ft_fill_board(char *filename, char **board, char tmp);
char	*prep_firstline(char *path);

#endif
