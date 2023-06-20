/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:39:54 by jbranche          #+#    #+#             */
/*   Updated: 2022/11/24 09:30:22 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_wcheck(char const *s, unsigned int start, size_t len)
{
	char			*string;
	unsigned int	size;

	string = ft_calloc(len + 1, sizeof(char));
	if (!string)
		return (0);
	size = 0;
	while (s[start] && size < len)
	{
		string[size] = s[start];
		start++;
		size++;
	}
	return (string);
}

char	*ft_nb_read_not(char *buffer, char *stock, int nb_read)
{
	free(buffer);
	if (nb_read == -1)
		return (0);
	return (stock);
}

char	*ft_read_buffer(int fd, char *stock)
{
	int		nb;
	char	*buffer;
	char	*temp;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	nb = read(fd, buffer, BUFFER_SIZE);
	if (nb < 1)
		return (ft_nb_read_not(buffer, stock, nb));
	if (!stock)
		stock = ft_calloc(1, sizeof(char));
	if (!stock)
		return (0);
	while (nb > 0)
	{
		buffer[nb] = '\0';
		temp = stock;
		stock = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_is_in(buffer, '\n'))
			break ;
		nb = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_nb_read_not(buffer, stock, nb));
}

char	*ft_split_line(char *line)
{
	int		sized;
	char	*bf;

	sized = 0;
	while (line[sized] && line[sized] != '\n')
		sized++;
	if (line[sized] == '\0')
		return (0);
	bf = ft_substr_wcheck(line, sized + 1, ft_strlen(line) - sized);
	if (!bf || !bf[0])
	{
		if (bf)
			free(bf);
		bf = 0;
	}
	line[sized + 1] = '\0';
	return (bf);
}

char	*get_next_line(int fd)
{
	static char	*bf;
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	l = ft_read_buffer(fd, bf);
	if (!l)
		return (0);
	bf = ft_split_line(l);
	return (l);
}
