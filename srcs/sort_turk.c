/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:22:16 by guilh             #+#    #+#             */
/*   Updated: 2026/06/16 23:10:01 by guilh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exe_move(t_stack **a, t_stack **b, int pos_a, int pos_b, t_bench *bench)
{
	int	size_a;
	int	size_b;

	size_a = ft_stacksize(*a);
	size_b = ft_stacksize(*b);
	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
	{
		while (pos_a > 0 && pos_b > 0)
		{
			rr(a, b, bench);
			pos_a--;
			pos_b--;
		}
	}
	else if (pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		while (pos_a < size_a && pos_b < size_b)
		{
			rrr(a, b, bench);
			pos_a++;
			pos_b++;
		}
	}
	rotate_single_a(a, pos_a, size_a, bench);
	rotate_single_b(b, pos_b, size_b, bench);
	pb(a, b, bench);
}

void	find(t_stack **a, t_stack **b, t_bench *bench, int size_a, int size_b)
{
	t_stack	*curr;
	int		pos_a;
	int		pos_b;
	int		min_ops;
	int		best_a;
	int		best_b;

	curr = *a;
	pos_a = 0;
	min_ops = 2147483647;
	while (1)
	{
		pos_b = get_target_b_pos(*b, curr->index);
		if (total_cost(pos_a, pos_b, size_a, size_b) < min_ops)
		{
			min_ops = total_cost(pos_a, pos_b, size_a, size_b);
			best_a = pos_a;
			best_b = pos_b;
		}
		pos_a++;
		curr = curr->next;
		if (curr == *a)
			break ;
	}
	exe_move(a, b, best_a, best_b, bench);
}

void	turk_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	target_a;
	int	min_pos;
	int	size_a;
	int	size_b;

	if (ft_stacksize(*a) > 3)
		pb(a, b, bench);
	if (ft_stacksize(*a) > 3)
		pb(a, b, bench);
	while (ft_stacksize(*a) > 3)
	{
		size_a = ft_stacksize(*a);
		size_b = ft_stacksize(*b);
		find(a, b, bench, size_a, size_b);
	}
	simple_3low(a, bench);
	while (*b)
	{
		target_a = get_target_a_pos(*a, (*b)->index);
		rotate_single_a(a, target_a, ft_stacksize(*a), bench);
		pa(a, b, bench);
	}
	min_pos = get_min_pos(*a);
	rotate_single_a(a, min_pos, ft_stacksize(*a), bench);
}
