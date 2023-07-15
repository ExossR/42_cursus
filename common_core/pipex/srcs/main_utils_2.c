/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:51:48 by asahonet          #+#    #+#             */
/*   Updated: 2023/01/02 17:56:07 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*cat;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (0);
	cat = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cat)
		return (0);
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	cat[i] = '\0';
	while (s2[n])
	{
		cat[i + n] = s2[n];
		n++;
	}
	cat[i + n] = '\0';
	return (cat);
}
