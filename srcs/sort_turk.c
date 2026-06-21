/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:22:16 by guilh             #+#    #+#             */
/*   Updated: 2026/06/21 19:49:59 by guilh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	total_best_cost(int *pos, int *size)
{
	int	rr;
	int	rrr;
	int	mix1;
	int	mix2;
	int	min;

	if (pos[A] > pos[B])
		rr = pos[A];
	else
		rr = pos[B];
	if ((size[A] - pos[A]) > (size[B] - pos[B]))
		rrr = size[A] - pos[A];
	else
		rrr = size[B] - pos[B];
	mix1 = pos[A] + (size[B] - pos[B]);
	mix2 = (size[A] - pos[A]) + pos[B];
	min = rr;
	if (rrr < min)
		min = rrr;
	if (mix1 < min)
		min = mix1;
	if (mix2 < min)
		min = mix2;
	return (min);
}

static void	find_best_cheapest(t_stack **a, t_stack **b, t_bench *bench, int *size)
{
	t_stack	*curr;
	int		min_ops;
	int		best[2];
	int		pos[2];

	curr = *a;
	pos[A] = 0;
	min_ops = 2147483647;
	while (1)
	{
		pos[B] = get_target_b_pos(*b, curr->index);
		if (total_best_cost(pos, size) < min_ops)
		{
			min_ops = total_best_cost(pos, size);
			best[A] = pos[A];
			best[B] = pos[B];
		}
		if (min_ops == 0)
			break ;
		pos[A]++;
		curr = curr->next;
		if (curr == *a)
			break ;
	}
	execute_move(a, b, best, bench);
}

static int	total_cost(int *pos, int *size)
{
	int	total_cost;
	int	cost[2];

	if (pos[A] <= size[A] / 2)
		cost[A] = pos[A];
	else
		cost[A] = size[A] - pos[A];
	if (pos[B] <= size[B] / 2)
		cost[B] = pos[B];
	else
		cost[B] = size[B] - pos[B];
	if ((pos[A] <= size[A] / 2 && pos[B] <= size[B] / 2) || (pos[A] > size[A]
			/ 2 && pos[B] > size[B] / 2))
	{
		if (cost[A] > cost[B])
			total_cost = cost[A];
		else
			total_cost = cost[B];
	}
	else
		total_cost = cost[A] + cost[B];
	return (total_cost);
}

static void	find_cheapest(t_stack **a, t_stack **b, t_bench *bench, int *size)
{
	t_stack	*curr;
	int		min_ops;
	int		best[2];
	int		pos[2];

	curr = *a;
	pos[A] = 0;
	min_ops = 2147483647;
	while (1)
	{
		pos[B] = get_target_b_pos(*b, curr->index);
		if (total_cost(pos, size) < min_ops)
		{
			min_ops = total_cost(pos, size);
			best[A] = pos[A];
			best[B] = pos[B];
		}
		pos[A]++;
		curr = curr->next;
		if (curr == *a)
			break ;
	}
	execute_move(a, b, best, bench);
}

void	turk_sort(t_stack **a, t_stack **b, t_bench *bench, int name)
{
	int	target_a;
	int	min_pos;
	int	size[2];

	if (ft_stacksize(*a) > 3 && ft_stacksize(*b) < 2)
		pb(a, b, bench);
	while (ft_stacksize(*a) > 3)
	{
		size[A] = ft_stacksize(*a);
		size[B] = ft_stacksize(*b);
		if (name == 's')
			find_cheapest(a, b, bench, size);
		else if (name == 'c')
			find_best_cheapest(a, b, bench, size);
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
