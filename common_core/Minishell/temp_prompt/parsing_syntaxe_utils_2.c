/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_syntaxe_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:58:48 by asahonet          #+#    #+#             */
/*   Updated: 2023/02/04 12:03:00 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	add_count_number_quote(char token, char c)
{
	int	count;

	count = 0;
	if (c == '"' && token == '"')
		count++;
	else if (c == '\'' && token == '\'')
		count++;
	return (count);
}
