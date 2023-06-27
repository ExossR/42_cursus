/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:09:44 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/20 18:40:28 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[i] > 96 && str[i] < 123)
	{
		str[i] -= 32;
		i++;
	}
	else
		i++;
	while (str[i])
	{
		if (!((str[i - 1] > 96 && str[i - 1] < 123)
				|| (str[i - 1] > 64 && str[i - 1] < 91)
				|| (str[i - 1] > 47 && str[i - 1] < 58)))
		{
			if (str[i] > 96 && str[i] < 123)
				str[i] -= 32;
		}
		else
			if (str[i] > 64 && str[i] < 91)
				str[i] += 32;
		i++;
	}
	return (str);
}

/*int	main(int argc, char **argv)
{
	char	*c;

	c = argv[1];
	printf("%s", ft_strcapitalize(c));
}*/
