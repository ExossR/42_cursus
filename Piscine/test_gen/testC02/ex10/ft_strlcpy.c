/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:13:44 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/20 16:18:00 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (0);
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

/*int	main(void)
{
	char src[] = "Mala est gangx";
	char dest[] = "ayaaaaa";

	printf("%u\n", ft_strlcpy(dest, src, 5));
	printf("%lu", strlcpy(dest, src, 5));
}*/
