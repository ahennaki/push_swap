/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:09:24 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/15 19:26:36 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	push_swap(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	set_index(*a, size + 1);
	if (size == 2 && !is_sorted(*a))
		swap_st(*a, 'a');
	else if (size == 3)
		sort_three(a);
	else if (size > 3 && !is_sorted(*a))
		sort(a, b);
	ft_free(a);
	ft_free(b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**str;
	int		i;

	i = 0;
	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!av[1][0])
		exit_point(NULL, NULL);
	while (av[++i])
	{
		str = ft_split(av[i], ' ');
		if (!check_input(str))
			exit_point(NULL, NULL);
		list_new(&a, str);
		free_str(str);
	}
	if (!is_dupnbr(a))
		exit_point(&a, NULL);
	push_swap(&a, &b);
	return (0);
}
