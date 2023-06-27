/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:42:58 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/21 19:30:22 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_verif_to_find(int pos_str, char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (str[pos_str] != to_find[i])
			return (0);
		i++;
		pos_str++;
	}
	return (1);
}

int	ft_pos_to_find(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			if (ft_verif_to_find(i, str, to_find))
				return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		y;

	i = 0;
	if (!to_find || to_find[i] == '\0')
		return (str);
	else
	{
		y = ft_pos_to_find(str, to_find);
		if (y == -1)
			return (0);
		else
			str += y;
	}
	return (str);
}

/*int main(void)
{
	char	str[] = "Bonjour la";
	char	tofind[] = "ou";
	
	printf("%s\n", ft_strstr(str, tofind));
	printf("%s\n", strstr(str, tofind));
}*/
