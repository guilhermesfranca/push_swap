/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:55:33 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/08 20:26:07 by guicarva         ###   ########.fr       */
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
	last->next = second;// o PROXIMO  do LAST   era o FIRST , agora e o SECOND
	third->prev = first;// o ANTERIOR do THIRD  era o SECOND, agora e o FIRST
	second->prev = last;// o ANTERIOR do SECOND era o FIRST, agora e o LAST
	second->next = first;//o PROXIMO  do SECOND era o THIRD, agora e o FIRST
	first->prev = second;//o ANTERIOR do FIRST  era o LAST, agora e o SECOND
	first->next = third;// o PROXIMO  do FIRST  era o SECOND, agora e o THIRD
	*stack = second;// muda o topo
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
