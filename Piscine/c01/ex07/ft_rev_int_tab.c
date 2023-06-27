/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:12:25 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/19 17:51:31 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	while (i < size / 2)
	{
		swap = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = swap;
		i++;
	}
}

/*int main(void)
{
	int tab[] = {2, 6, 0, -4};
	int i;
	
	i = 0;
	ft_rev_int_tab(tab, 4);
	while (i < 4)
	{
		printf("%d", tab[i]);
		i++;
	}
}*/
