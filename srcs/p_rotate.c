/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:27:11 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/08 21:40:19 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **orin, t_stack **dest)
{
	t_stack	*node_push;
	t_stack	*last_orin;
	t_stack	*last_dest;

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


void	ra(t_stack **a)
{
	if ((*a)->next == *a)
		return ;
	*a = (*a)->next;
	ft_printf(1, "ra\n");
}

void	rb(t_stack **b)
{
	if ((*b)->next == *b)
		return ;
	*b = (*b)->next;
	ft_printf(1, "rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	if ((*a)->next == *a)
		return ;
	*a = (*a)->next;
	if ((*b)->next == *b)
		return ;
	*b = (*b)->next;
	ft_printf(1, "rr\n");
}
