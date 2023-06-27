/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:16:49 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/20 19:23:21 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	*c1;
	char	*c2;
	
	c1 = "Bonjour";
	c2 = "Bonjouriiiii";

	printf("%d\n", ft_strcmp(c1, c2));
	printf("%d", strcmp(c1, c2));
}*/
