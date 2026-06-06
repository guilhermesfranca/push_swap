/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotate_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:47:17 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/06 20:10:33 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf(1, "pa\n");
}

void	rotate_r(t_stack **top)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*penultimate;

	if (!top || !*top || !(*top)->next)
		return ;
	first = *top;
	penultimate = *top;
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	last = penultimate->next;
	penultimate->next = NULL;
	last->next = first;
	*top = last;
}

void	rra(t_stack **a)
{
	rotate_r(a);
	ft_printf(1, "rra\n");
}

void	rrb(t_stack **b)
{
	rotate_r(b);
	ft_printf(1, "rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rotate_r(a);
	rotate_r(b);
	ft_printf(1, "rrr\n");
}
