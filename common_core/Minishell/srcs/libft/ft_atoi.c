/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:33:26 by jbranche          #+#    #+#             */
/*   Updated: 2022/12/06 17:30:37 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *string)
{
	int	i;
	int	output;
	int	neg;

	i = 0;
	neg = 1;
	output = 0;
	while (string[i] == ' ' || string[i] == '\t' || string[i] == '\n'
		|| string[i] == '\v' || string[i] == '\f' || string[i] == '\r')
		i++;
	if (string[i] == '+' || string[i] == '-')
		neg = (string[i++] - 44) * -1;
	while (string[i] >= '0' && string[i] <= '9')
	{
		output = output * 10;
		if (output + string[i] - 48 > 2147483647)
			return (-2147483648);
		output += string[i] - 48;
		i++;
	}
	return (output * neg);
}
