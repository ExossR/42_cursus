/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:25:01 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/29 11:16:07 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i])
		i++;
	str = malloc(i * sizeof(char));
	if (i == 0)
	{
		str[i] = '\0';
		return (str);
	}
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	(void) argc;
	char *str;

	str = ft_strdup(argv[1]);
	printf("%s\n", str);
}
