/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:36:54 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/21 11:50:52 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	uniq_in_list(t_swap *list, int nb)
{
	while (list->next != 0)
	{
		if (list->content == nb)
			return (0);
		list = list->next;
	}
	if (list->content == nb)
		return (0);
	return (1);
}

int	verif_number(char **arr)
{
	int			i;
	int			j;
	long long	number;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (!((arr[i][j] >= 48 && arr[i][j] <= 57)
				|| (j == 0 && arr[i][j] == 45)))
				return (0);
			j++;
		}
		number = ft_atoi(arr[i]);
		if (number > 2147483647 || number < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

t_swap	*create_list(char **arr)
{
	t_swap	*list;
	int		i;

	list = new_elem((int)ft_atoi(arr[0]));
	i = 1;
	while (arr[i])
	{
		if (uniq_in_list(list, (int)ft_atoi(arr[i])) == 0)
		{
			ft_lstclear(list);
			return (0);
		}
		ft_lstadd_back(list, new_elem((int)ft_atoi(arr[i])));
		i++;
	}
	return (list);
}

t_swap	*verif_arg(int argc, char **argv)
{
	char	**arr;
	t_swap	*list;

	arr = 0;
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (arr[0] == 0)
			return (0);
		else if (verif_number(arr) == 1)
		{
			list = create_list(arr);
			free_arr(arr);
			return (list);
		}
	}
	else if (verif_number(++argv) == 1)
		return (create_list(argv));
	if (arr)
		free_arr(arr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_swap	*list;

	if (argc == 1)
		return (0);
	list = verif_arg(argc, argv);
	if (list == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (size_list(list) > 5)
		list = sort_stack(list, size_list(list));
	else if (size_list(list) != 1)
		list = sort_small_stack(list, size_list(list));
}
