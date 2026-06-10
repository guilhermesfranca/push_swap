/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:55:33 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/10 19:11:17 by guilh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;

	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = first->next;
	if (second->next == first)
	{
		*stack = second;
		return ;
	}
	last = first->prev;
	third = second->next;
	last->next = second;
	third->prev = first;
	second->prev = last;
	second->next = first;
	first->prev = second;
	first->next = third;
	*stack = second;
}

void	sa(t_stack **a, t_bench *bench)
{
	swap(a);
	bench->total_ops++;
	bench->sa++;
	ft_printf(1, "sa\n");
}

void	sb(t_stack **b, t_bench *bench)
{
	swap(b);
	bench->total_ops++;
	bench->sb++;
	ft_printf(1, "sb\n");
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	swap(a);
	swap(b);
	bench->total_ops++;
	bench->ss++;
	ft_printf(1, "ss\n");
}
