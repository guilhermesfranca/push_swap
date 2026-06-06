/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:27:11 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/06 20:09:33 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf(1, "pb\n");
}

void	rotate(t_stack **top)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!top || !*top || !(*top)->next)
		return ;
	first = *top;
	second = first->next;
	last = ft_stacklast(*top);
	last->next = first;
	first->next = NULL;
	*top = second;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf(1, "ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf(1, "rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf(1, "rr\n");
}
