/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:38:46 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/16 11:44:18 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*int		main(void)
{
	int a, b;
	a = 20;
	b = 3;

	ft_ultimate_div_mod(&a, &b);
	printf("div/a:%d mod/b:%d", a, b);
}*/
