/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:19:48 by asahonet          #+#    #+#             */
/*   Updated: 2022/10/02 20:38:26 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct s_struct
{
	char			*number;
	char			*str;
}	t_number;

char	*convert_3_to_english(char array[3], t_number **numbers);

char	*ft_strcat(char *dest, char *src);

void	ft_putstr(char *str);

void	ft_putnbr(int nbr);

char	*ft_strdup(char *src);

int		ft_strlen(char *str);

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2);

char	*ft_strcpy(char *dest, char *src);

char	*find_trad(char *target, t_number **tab);

char	*ft_strcat(char *dest, char *src);

int		count_line(char *path);

void	creating_array(t_number **tab, char *path);

char	**split_number(char *str, int i, int j);

void	print_all_number(char **tab, t_number **dict);

int		check_args(int argc, char **argv);

int		ft_atoi_check_unsignedint(char *str);

int		ft_mod(int mod);

char	*add_val_tabrest(char *result, char *str, int key);

char	*init_tab_zero(char *str);

char	*put_in_chain(char letter, char *buf);

char	*put_in_chain_tenth(char letter, char *buf);

void	print_power(int i, t_number **tab);

int		find_number_tab_size(char **tab);

#endif
