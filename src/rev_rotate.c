/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:20:00 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/14 16:26:03 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_list	*befor_last(t_list *lst)
{
	while (lst && lst->next)
	{
		if (!lst->next->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	rev_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*blast;

	if (!*lst || !(*lst)->next)
		return ;
	last = ft_lstlast(*lst);
	blast = befor_last(*lst);
	last->next = *lst;
	*lst = last;
	blast->next = NULL;
}

void	rev_rotate_st(t_list **lst, char c)
{
	rev_rotate(lst);
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}

void	rev_rotate_ab(t_list **a, t_list **b, char c)
{
	rev_rotate(a);
	rev_rotate(b);
	if (c == 'r')
		ft_printf("rrr\n");
}

void	rev_rotate_cost(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rev_rotate_ab(a, b, 'r');
	}
}
