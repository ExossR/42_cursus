/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:01:48 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/26 05:55:03 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuffer(int fd, char *rest)
{
	int		rd;
	char	*output;
	char	buf[BUFFER_SIZE + 1];

	if (rest && gnl_strchr(rest, '\n') != -1)
		output = gnl_strdup(rest);
	else
	{
		output = gnl_strdup(rest);
		buf[0] = '\0';
		rd = 1;
		while (rd != 0 && gnl_strchr(buf, '\n') == -1)
		{
			rd = read(fd, buf, BUFFER_SIZE);
			if (rd == -1)
			{
				free(output);
				output = 0;
				return (0);
			}
			buf[rd] = '\0';
			output = gnl_strjoin(output, buf);
		}
	}
	return (output);
}

char	*read_after(char *buf, int pos_n)
{
	int		size;
	int		k;
	int		i;
	char	*s;

	if (pos_n == -1 || !buf)
		return (0);
	i = 0;
	k = pos_n + 1;
	size = gnl_strlen(buf) - pos_n;
	s = malloc(size);
	if (!s)
		return (0);
	s[0] = '\0';
	while (buf[k] && i < size)
	{
		s[i] = buf[k];
		i++;
		k++;
	}
	s[i] = '\0';
	return (s);
}

char	*read_until(char *buf, int posnsize)
{
	int		i;
	char	*s;

	if (posnsize == -1)
		posnsize = gnl_strlen(buf);
	i = 0;
	s = gnl_calloc(posnsize + 2, sizeof(char));
	if (!s)
		return (0);
	while (buf[i] && i <= posnsize)
	{
		s[i] = buf[i];
		i++;
	}
	free(buf);
	s[i] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*rest = 0;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	buffer = readbuffer(fd, rest);
	if (!buffer)
		return (0);
	rest = read_after(buffer, gnl_strchr(buffer, '\n'));
	buffer = read_until(buffer, gnl_strchr(buffer, '\n'));
	if (buffer[0] == 0)
	{
		free(buffer);
		return (0);
	}
	return (buffer);
}
