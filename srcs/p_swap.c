/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:55:33 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/06 20:09:02 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **top)
{
	t_stack	*first;
	t_stack	*second;

	if (!top || !*top || !(*top)->next)
		return ;
	first = *top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*top = second;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf(1, "sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf(1, "sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf(1, "ss\n");
}

void	push(t_stack **dest, t_stack **origin)
{
	t_stack	*tmp;

	if (!origin || !*origin)
		return ;
	tmp = *origin;
	*origin = (*origin)->next;
	tmp->next = *dest;
	*dest = tmp;
}
