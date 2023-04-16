/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:09:44 by aennaki           #+#    #+#             */
/*   Updated: 2023/03/15 18:57:43 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line.h"
# include "ft_printf.h"
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	int				tpos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);

void	rev_rotate_cost(t_list **a, t_list **b, int *cost_a, int *cost_b);
void	rotate_cost(t_list **a, t_list **b, int *cost_a, int *cost_b);
void	rotate_st_cost(t_list **lst, char c, int *cost);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	push_a(t_list **a, t_list **b, int print);
void	push_b(t_list **a, t_list **b, int print);
void	swap_st(t_list *lst, char c);
void	swap_ab(t_list *a, t_list *b, char c);
void	rev_rotate_st(t_list **lst, char c);
void	rev_rotate_ab(t_list **a, t_list **b, char c);
void	rotate_st(t_list **lst, char c);
void	rotate_ab(t_list **a, t_list **b, char c);
void	exit_point(t_list **a, t_list **b);
void	set_index(t_list *lst, int size);
void	sort_three(t_list **lst);
void	push_2b(t_list **a, t_list **b);
void	set_cost(t_list **a, t_list **b);
void	min_costmove(t_list **a, t_list **b);
void	sort(t_list **a, t_list **b);
void	set_tpos(t_list **a, t_list **b);
void	incr_ij(char *s1, char *s2, int *i, int *j);
void	ft_free(t_list **lst);
void	list_new(t_list **lst, char **av);
void	free_str(char **str);
void	set_pos(t_list **lst);

int		ft_lstsize(t_list *lst);
int		is_sorted(t_list *lst);
int		min_index(t_list **lst);
int		check_input(char **str);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
int		is_dupnbr(t_list *lst);

char	**ft_split(char *s, char c);
long	ft_atoi(char *str);

#endif
