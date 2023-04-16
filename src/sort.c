/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:43:36 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/15 17:18:30 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_three(t_list **lst)
{
	int		max_i;
	t_list	*tmp;

	if (is_sorted(*lst))
		return ;
	tmp = *lst;
	max_i = tmp->index;
	while (tmp)
	{
		if (tmp->index > max_i)
			max_i = tmp->index;
		tmp = tmp->next;
	}
	if ((*lst)->index == max_i)
		rotate_st(lst, 'a');
	else if ((*lst)->next->index == max_i)
		rev_rotate_st(lst, 'a');
	if ((*lst)->index > (*lst)->next->index)
		swap_st(*lst, 'a');
}

void	push_2b(t_list **a, t_list **b)
{
	const int	size = ft_lstsize(*a);
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (size > 6 && i < size && j < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			push_b(a, b, 1);
			j++;
		}
		else
			rotate_st(a, 'a');
		i++;
	}
	while (size - j > 3)
	{
		push_b(a, b, 1);
		j++;
	}
}

void	rotate_list(t_list **a)
{
	int	min_pos;
	int	size;

	size = ft_lstsize(*a);
	min_pos = min_index(a);
	if (min_pos > size / 2)
	{
		while (min_pos < size)
		{
			rev_rotate_st(a, 'a');
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			rotate_st(a, 'a');
			min_pos--;
		}
	}
}

void	sort(t_list **a, t_list **b)
{
	push_2b(a, b);
	sort_three(a);
	while (*b)
	{
		set_tpos(a, b);
		set_cost(a, b);
		min_costmove(a, b);
	}
	if (!is_sorted(*a))
		rotate_list(a);
}
