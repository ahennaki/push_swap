/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:53:47 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/16 17:05:22 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i]
		&& (unsigned char)str1[i] == (unsigned char)str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	check_instraction(t_list **a, t_list **b, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		push_a(a, b, 0);
	else if (!ft_strcmp(str, "pb\n"))
		push_b(a, b, 0);
	else if (!ft_strcmp(str, "sa\n"))
		swap_st(*a, 'c');
	else if (!ft_strcmp(str, "sb\n"))
		swap_st(*b, 'c');
	else if (!ft_strcmp(str, "ss\n"))
		swap_ab(*a, *b, 'c');
	else if (!ft_strcmp(str, "ra\n"))
		rotate_st(a, 'c');
	else if (!ft_strcmp(str, "rb\n"))
		rotate_st(b, 'c');
	else if (!ft_strcmp(str, "rr\n"))
		rotate_ab(a, b, 'c');
	else if (!ft_strcmp(str, "rra\n"))
		rev_rotate_st(a, 'c');
	else if (!ft_strcmp(str, "rrb\n"))
		rev_rotate_st(b, 'c');
	else if (!ft_strcmp(str, "rrr\n"))
		rev_rotate_ab(a, b, 'c');
	else
		exit_point(a, b);
}

void	checker(t_list **a, t_list **b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		check_instraction(a, b, str);
		free(str);
		str = get_next_line(0);
	}
	if (is_sorted(*a) && !ft_lstsize(*b))
		ft_printf("OK");
	else
		ft_printf("KO");
	ft_free(a);
	ft_free(b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;
	char	**str;

	a = NULL;
	b = NULL;
	size = 0;
	if (ac < 2)
		return (0);
	if (!av[1][0])
		exit_point(NULL, NULL);
	while (av[++size])
	{
		str = ft_split(av[size], ' ');
		if (!check_input(str))
			exit_point(NULL, NULL);
		list_new(&a, str);
		free_str(str);
	}
	if (!is_dupnbr(a))
		exit_point(&a, NULL);
	checker(&a, &b);
	return (0);
}
