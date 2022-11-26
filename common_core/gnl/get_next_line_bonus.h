/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:50:48 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/26 04:37:16 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		gnl_strlen(const char *s);
int		gnl_strchr(char *s, char c);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strdup(char *s);
void	*gnl_calloc(size_t nmemb, size_t size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE    42
# endif

#endif
