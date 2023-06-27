/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:46:31 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/21 13:55:44 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	y;

	i = 0;
	y = 0;
	while (dest[i])
		i++;
	while (src[y] && y < nb)
	{
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(int argc, char **argv)
{
	char dest[30] = "bonjour ";
	char dest1[30] = "bonjour ";

	printf("%s\n", ft_strncat(dest, argv[1], 8));
	printf("%s", strncat(dest1, argv[1], 8));
}*/
