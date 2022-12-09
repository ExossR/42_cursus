/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:02:19 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/30 12:27:51 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	gnl_strchr(char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*cat;

	i = 0;
	n = 0;
	cat = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!cat)
		return (0);
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		cat[i + n] = s2[n];
		n++;
	}
	cat[i + n] = '\0';
	free(s1);
	return (cat);
}

char	*gnl_strdup(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
	{
		s = malloc(1 * sizeof(char));
		s[0] = '\0';
	}
	str = malloc((gnl_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	i;
	char	*c;

	if (nmemb > 4294967295 || size > 4294967295)
		return (0);
	s = malloc(size * nmemb);
	if (s == 0)
		return (0);
	i = 0;
	c = s;
	while (i < nmemb)
	{
		c[i] = 0;
		i++;
	}
	return (c);
}
