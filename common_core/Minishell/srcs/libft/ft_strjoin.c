/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:15:05 by jbranche          #+#    #+#             */
/*   Updated: 2023/01/13 10:56:08 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	output = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (output == 0)
		return (0);
	while (s1[i] != '\0')
	{
		output[j] = s1[i++];
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		output[j] = s2[i++];
		j++;
	}
	output[j] = '\0';
	return (output);
}

static int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
int main(int argc, char const *argv[])
{
	printf("S1 :%s S2 :%s Cat : %s\n","Bonjour", 
	"a tous", ft_strjoin("Bonjour", "a tous"));
	return 0;
}
*/
