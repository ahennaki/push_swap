/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:05:39 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/13 18:43:18 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		signe;

	i = 0;
	signe = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (res * signe);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	incr_ij(char *s1, char *s2, int *i, int *j)
{
	if (s1[*i] == '+' && s2[*j] == '+')
	{
		(*i)++;
		(*j)++;
	}
	if (s1[*i] == '+' && ft_isdigit(s2[*j]))
		(*i)++;
	if (s2[*j] == '+' && ft_isdigit(s1[*i]))
		(*j)++;
	if (s1[*i] == '-' && s2[*j] == '-')
	{
		(*i)++;
		(*j)++;
	}
	while (s1[*i] && s1[*i] == '0')
		(*i)++;
	while (s2[*j] && s2[*j] == '0')
		(*j)++;
}
