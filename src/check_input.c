/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:46:01 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/15 19:00:52 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (0);
	return (1);
}

// static int	ft_nbrcmp(char *s1, char *s2)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	incr_ij(s1, s2, &i, &j);
// 	while (s1[i] && s2[j] && s1[i] == s2[j])
// 	{
// 		i++;
// 		j++;
// 	}
// 	return (s1[i] - s2[j]);
// }

int	is_dupnbr(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	set_pos(&lst);
	tmp2 = lst;
	while (tmp2)
	{
		tmp = lst;
		while (tmp)
		{
			if (tmp->pos != tmp2->pos && tmp->content == tmp2->content)
				return (0);
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	return (1);
}

static int	is_zero(char *str)
{
	int	i;

	i = 0;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i])
		return (0);
	return (1);
}

int	check_input(char **str)
{
	int			i;
	static int	zero;

	if (!*str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (!is_number(str[i]))
			return (0);
		zero += is_zero(str[i]);
		if (zero > 1)
			return (0);
	}
	return (1);
}
