/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:37:47 by guilh             #+#    #+#             */
/*   Updated: 2026/06/19 23:24:14 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	execute_move(t_stack **a, t_stack **b, int *best, t_bench *bench)
{
	int	size[2];

	size[A] = ft_stacksize(*a);
	size[B] = ft_stacksize(*b);
	if (best[A] <= size[A] / 2 && best[B] <= size[B] / 2)
	{
		while (best[A] > 0 && best[B] > 0)
		{
			rr(a, b, bench);
			best[A]--;
			best[B]--;
		}
	}
	else if (best[A] > size[A] / 2 && best[B] > size[B] / 2)
	{
		while (best[A] < size[A] && best[B] < size[B])
		{
			rrr(a, b, bench);
			best[A]++;
			best[B]++;
		}
	}
	rotate_single_a(a, best[A], size[A], bench);
	rotate_single_b(b, best[B], size[B], bench);
	pb(a, b, bench);
}
