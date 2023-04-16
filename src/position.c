/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:32:41 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/13 18:43:28 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	set_pos(t_list **lst)
{
	t_list	*tmp;
	int		i;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	i = 0;
	while (tmp)
	{
		tmp->pos = i++;
		tmp = tmp->next;
	}
}

int	min_index(t_list **lst)
{
	t_list	*tmp;
	int		min_i;
	int		p;

	tmp = *lst;
	set_pos(lst);
	min_i = tmp->index;
	p = tmp->pos;
	while (tmp)
	{
		if (min_i > tmp->index)
		{
			min_i = tmp->index;
			p = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (p);
}

static int	get_tpos(t_list **a, int b_index, int tidx, int tpos)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < tidx)
		{
			tidx = tmp->index;
			tpos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (tidx != INT_MAX)
		return (tpos);
	tmp = *a;
	while (tmp)
	{
		if (tmp->index < tidx)
		{
			tidx = tmp->index;
			tpos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (tpos);
}

void	set_tpos(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		tpos;

	tmp = *b;
	set_pos(a);
	set_pos(b);
	tpos = 0;
	while (tmp)
	{
		tpos = get_tpos(a, tmp->index, INT_MAX, tpos);
		tmp->tpos = tpos;
		tmp = tmp->next;
	}
}
