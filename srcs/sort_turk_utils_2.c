/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:37:47 by guilh             #+#    #+#             */
/*   Updated: 2026/06/16 23:00:57 by guilh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	assing_cost(int pos, int size)
{
	int	cost;

	if (pos <= size / 2)
		cost = pos;
	else
		cost = size - pos;
	return (cost);
}

int	total_cost(int pos_a, int pos_b, int size_a, int size_b)
{
	int	total_cost;
	int	cost_a;
	int	cost_b;

	cost_a = assing_cost(pos_a, size_a);
	cost_b = assing_cost(pos_b, size_b);
	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
	{
		if (cost_a > cost_b)
			total_cost = cost_a;
		else
			total_cost = cost_b;
	}
	else if (pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		if (cost_a > cost_b)
			total_cost = cost_a;
		else
			total_cost = cost_b;
	}
	else
		total_cost = cost_a + cost_b;
	return (total_cost);
}

void	rotate_single_a(t_stack **a, int pos_a, int size_a, t_bench *bench)
{
	if (pos_a <= size_a / 2)
		while (pos_a-- > 0)
			ra(a, bench);
	else
		while (pos_a++ < size_a)
			rra(a, bench);
}

void	rotate_single_b(t_stack **b, int pos_b, int size_b, t_bench *bench)
{
	if (pos_b <= size_b / 2)
		while (pos_b-- > 0)
			rb(b, bench);
	else
		while (pos_b++ < size_b)
			rrb(b, bench);
}
