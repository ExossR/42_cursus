/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahonet <asahonet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:35:49 by asahonet          #+#    #+#             */
/*   Updated: 2022/12/21 13:01:41 by asahonet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_swap
{
	int				content;
	struct s_swap	*next;
}	t_swap;

/*---------------ft_split.c---------------*/
char		**ft_split(char *s, char c);

/*---------------main_utils.c---------------*/
void		free_arr(char **arr);
long long	ft_atoi(const char *nptr);
t_swap		*new_elem(int number);
void		ft_lstadd_back(t_swap *lst, t_swap *new);
int			ft_strlen(char *s);

/*---------------main_utils_2.c---------------*/
void		ft_lstclear(t_swap *lst);

/*---------------sort.c---------------*/
void		swap(t_swap **lst, int i);
void		sswap(t_swap **lst_a, t_swap **lst_b);
void		push_a(t_swap **lst_a, t_swap **lst_b);
void		push_b(t_swap **lst_a, t_swap **lst_b);

/*---------------sort_utils.c---------------*/
t_swap		*ft_lstlast(t_swap *lst);
void		rotate(t_swap **lst, int i);
void		rrotate(t_swap **lst_a, t_swap **lst_b);
void		reverse_rotate(t_swap **lst, int i);
void		rrrotate(t_swap **lst_a, t_swap **lst_b);

/*---------------swap.c---------------*/
t_swap		*sort_stack(t_swap *list, int size);
t_swap		*sort_small_stack(t_swap *list, int size);
int			is_sorted(t_swap *list);

/*---------------swap_utils.c---------------*/
int			get_max_number_stack(t_swap *list);
int			stack_is_sort(t_swap *list);
int			size_list(t_swap *list);
int			have_neg_in(t_swap *list);
void		nullify_neg(t_swap *list);

/*---------------swap_sort_small.c---------------*/
t_swap		*sort_three(t_swap *list);
t_swap		*sort_four(t_swap *list);
t_swap		*sort_five(t_swap *list);

#endif
