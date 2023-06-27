/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:52:41 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/19 11:04:44 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	swap;
	int	i;
	int	j;

	i = 0;
	size--;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (tab[j] > tab[j + 1])
			{
				swap = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}

/*int	main(void)
{
	int tab[] = {2, 5, 1, 4};
	int i, a;

	i = 0;
	while (i < 4)
	{
		a = tab[i] + 48;
		write(1, &a, 1);
		i++;
	}
	write(1, "\n", 1);
	ft_sort_int_tab(tab, 4);
	i = 0;
	while (i < 4)
	{
		a = tab[i] + 48;
		write(1, &a, 1);
		i++;
	}
}*/
