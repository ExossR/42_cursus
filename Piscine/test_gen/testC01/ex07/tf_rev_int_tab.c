/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:12:25 by asahonet          #+#    #+#             */
/*   Updated: 2022/09/19 12:01:08 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	size--;
	while (i < size / 2)
	{
		swap = tab[i];
		tab[i] = tab[size - i];
		tab[size - i] = swap;
		i++;
	}
}

/*int main(void)
{
	int tab[] = {1, 2, 3, 4, 5};
	int i = 0;
	ft_rev_int_tab(tab, 5);
	while (i < 5)
	{
		tab[i] += 48;
		write(1, &tab[i], 1);
		i++;
	}
}*/
