/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotate_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:47:17 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/10 20:36:12 by guilh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	push(b, a);
	bench->total_ops++;
	bench->pa++;
	ft_printf(1, "pa\n");
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	push(a, b);
	bench->total_ops++;
	bench->pb++;
	ft_printf(1, "pb\n");
}

void	rra(t_stack **a, t_bench *bench)
{
	if ((*a)->prev == *a)
		return ;
	*a = (*a)->prev;
	bench->total_ops++;
	bench->rra++;
	ft_printf(1, "rra\n");
}

void	rrb(t_stack **b, t_bench *bench)
{
	if ((*b)->prev == *b)
		return ;
	*b = (*b)->prev;
	bench->total_ops++;
	bench->rrb++;
	ft_printf(1, "rrb\n");
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	if ((*a)->prev == *a)
		return ;
	*a = (*a)->prev;
	if ((*b)->prev == *b)
		return ;
	*b = (*b)->prev;
	bench->total_ops++;
	bench->rrr++;
	ft_printf(1, "rrr\n");
}
