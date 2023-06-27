/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:59:54 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/16 12:06:42 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_strlen(char *str)
{
	int i;

	while(str[i])
		i++;
	return (i);
}

int	main(void)
{
	char str[] = "Oui.";

	printf("%d", ft_strlen(str));
}
