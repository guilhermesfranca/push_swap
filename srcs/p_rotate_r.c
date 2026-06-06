/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotate_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:47:17 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/06 19:01:59 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **sa, t_stack **sb)
{
	push(sa, sb);
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

void	rra(t_stack **sa)
{
	rotate_r(sa);
	ft_printf(1, "rra\n");
}

void	rrb(t_stack **sb)
{
	rotate_r(sb);
	ft_printf(1, "rrb\n");
}

void	rrr(t_stack **sa, t_stack **sb)
{
	rotate_r(sa);
	rotate_r(sb);
	ft_printf(1, "rrr\n");
}
