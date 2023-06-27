/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:02:08 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/16 11:37:54 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int		main(void)
{
	int div, mod;

	ft_div_mod(20, 4, &div, &mod);

	printf("div:%d mod:%d", div, mod);
}*/
