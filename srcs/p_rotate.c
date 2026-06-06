/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:27:11 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/06 19:05:59 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stack **sa, t_stack **sb)
{
	push(sb, sa);
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

void	ra(t_stack **sa)
{
	rotate(sa);
	ft_printf(1, "ra\n");
}

void	rb(t_stack **sb)
{
	rotate(sb);
	ft_printf(1, "rb\n");
}

void	rr(t_stack **sa, t_stack **sb)
{
	rotate(sa);
	rotate(sb);
	ft_printf(1, "rr\n");
}
