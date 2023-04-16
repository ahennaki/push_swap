/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:19:40 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/13 18:43:42 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	last = ft_lstlast(*lst);
	*lst = (*lst)->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	rotate_st(t_list **lst, char c)
{
	rotate(lst);
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	rotate_ab(t_list **a, t_list **b, char c)
{
	rotate(a);
	rotate(b);
	if (c == 'r')
		ft_printf("rr\n");
}

void	rotate_st_cost(t_list **lst, char c, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate_st(lst, c);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rev_rotate_st(lst, c);
			(*cost)++;
		}
	}
}

void	rotate_cost(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate_ab(a, b, 'r');
	}
}
