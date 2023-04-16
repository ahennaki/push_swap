/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:19:14 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/13 18:43:52 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap(t_list *lst)
{
	int	tmp;

	if (!lst || !lst->next)
		return ;
	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
	tmp = lst->index;
	lst->index = lst->next->index;
	lst->next->index = tmp;
}

void	swap_st(t_list *lst, char c)
{
	swap(lst);
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
}

void	swap_ab(t_list *a, t_list *b, char c)
{
	swap(a);
	swap(b);
	if (c == 's')
		ft_printf("ss\n");
}
