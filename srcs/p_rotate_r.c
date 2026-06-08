/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotate_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:47:17 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/08 21:41:08 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf(1, "pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf(1, "pb\n");
}

void	rra(t_stack **a)
{
	if ((*a)->prev == *a)
		return ;
	*a = (*a)->prev;
	ft_printf(1, "rra\n");
}

void	rrb(t_stack **b)
{
	if ((*b)->prev == *b)
		return ;
	*b = (*b)->prev;
	ft_printf(1, "rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((*a)->prev == *a)
		return ;
	*a = (*a)->prev;
	if ((*b)->prev == *b)
		return ;
	*b = (*b)->prev;
	ft_printf(1, "rrr\n");
}
