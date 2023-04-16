/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:30:52 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/13 18:43:33 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	push_a(t_list **a, t_list **b, int print)
{
	push(b, a);
	if (print)
		ft_printf("pa\n");
}

void	push_b(t_list **a, t_list **b, int print)
{
	push(a, b);
	if (print)
		ft_printf("pb\n");
}
