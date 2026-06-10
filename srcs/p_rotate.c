/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:27:11 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/10 19:11:32 by guilh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_part2(t_stack **dest, t_stack *node_push)
{
	t_stack	*last_dest;

	if (*dest == NULL)
	{
		*dest = node_push;
		node_push->next = *dest;
		node_push->prev = *dest;
	}
	else
	{
		last_dest = (*dest)->prev;
		node_push->next = *dest;
		node_push->prev = last_dest;
		last_dest->next = node_push;
		(*dest)->prev = node_push;
		*dest = node_push;
	}
}

void	push(t_stack **orin, t_stack **dest)
{
	t_stack	*node_push;
	t_stack	*last_orin;

	if (!orin || !*orin)
		return ;
	node_push = *orin;
	if (node_push->next == node_push)
		*orin = NULL;
	else
	{
		last_orin = node_push->prev;
		*orin = node_push->next;
		(*orin)->prev = last_orin;
		last_orin->next = *orin;
	}
	push_part2(dest, node_push);
}


void	ra(t_stack **a, t_bench *bench)
{
	if ((*a)->next == *a)
		return ;
	*a = (*a)->next;
	bench->total_ops++;
	bench->ra++;
	ft_printf(1, "ra\n");
}

void	rb(t_stack **b, t_bench *bench)
{
	if ((*b)->next == *b)
		return ;
	*b = (*b)->next;
	bench->total_ops++;
	bench->rb++;
	ft_printf(1, "rb\n");
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	if ((*a)->next == *a)
		return ;
	*a = (*a)->next;
	if ((*b)->next == *b)
		return ;
	*b = (*b)->next;
	bench->total_ops++;
	bench->rr++;
	ft_printf(1, "rr\n");
}
