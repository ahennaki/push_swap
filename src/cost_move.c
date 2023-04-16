/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:23:57 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/13 18:43:08 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	set_cost(t_list **a, t_list **b)
{
	t_list	*atmp;
	t_list	*btmp;
	int		la;
	int		lb;

	atmp = *a;
	btmp = *b;
	la = ft_lstsize(atmp);
	lb = ft_lstsize(btmp);
	while (btmp)
	{
		btmp->cost_b = btmp->pos;
		if (btmp->pos > lb / 2)
			btmp->cost_b = (lb - btmp->pos) * -1;
		btmp->cost_a = btmp->tpos;
		if (btmp->tpos > la / 2)
			btmp->cost_a = (la - btmp->tpos) * -1;
		btmp = btmp->next;
	}
}

int	nbrabs(int nbr)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	move(t_list **a, t_list **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_cost(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_cost(a, b, &cost_a, &cost_b);
	rotate_st_cost(a, 'a', &cost_a);
	rotate_st_cost(b, 'b', &cost_b);
	push_a(a, b, 1);
}

void	min_costmove(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		min;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	min = INT_MAX;
	while (tmp)
	{
		if (nbrabs(tmp->cost_a) + nbrabs(tmp->cost_b) < nbrabs(min))
		{
			min = nbrabs(tmp->cost_b) + nbrabs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move(a, b, cost_a, cost_b);
}
