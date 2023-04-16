/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:35:32 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/15 18:36:01 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->index = 0;
	lst->pos = -1;
	lst->tpos = -1;
	lst->cost_a = -1;
	lst->cost_b = -1;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}

void	list_new(t_list **lst, char **av)
{
	long	nbr;
	int		i;
	int		ac;

	ac = 0;
	while (av[ac])
		ac++;
	i = -1;
	while (++i < ac)
	{
		nbr = ft_atoi(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			exit_point(lst, NULL);
		if (!*lst)
			*lst = ft_lstnew(nbr);
		else
			ft_lstadd_back(lst, ft_lstnew(nbr));
	}
}

void	set_index(t_list *lst, int size)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		content;

	while (--size)
	{
		tmp = lst;
		content = INT_MIN;
		tmp2 = NULL;
		while (tmp)
		{
			if (tmp->content == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->content > content && tmp->index == 0)
			{
				content = tmp->content;
				tmp2 = tmp;
				tmp = lst;
			}
			else
				tmp = tmp->next;
		}
		if (tmp2)
			tmp2->index = size;
	}
}
