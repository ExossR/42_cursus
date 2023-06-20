/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:05:41 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/10 11:26:48 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strlen(const char *s);

char	*ft_strchr(const char *string, int searched_char)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *) string;
	if (searched_char == 0)
		return (&temp[ft_strlen(temp)]);
	while (string[i] != '\0')
	{
		temp = (char *)&string[i];
		if (*temp == (char) searched_char)
			return (temp);
		i++;
	}
	return (0);
}

static int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
