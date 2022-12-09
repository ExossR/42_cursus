/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:31:43 by asahonet          #+#    #+#             */
/*   Updated: 2022/11/07 15:17:17 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb > 4294967295 || size > 4294967295)
		return (0);
	s = malloc(size * nmemb);
	if (s == 0)
		return (0);
	ft_bzero(s, nmemb);
	return (s);
}
