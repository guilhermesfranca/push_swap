/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:57:59 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/08 22:54:39 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	invert(t_stack **stack)
{
	t_stack	*current;

	if (!stack)
		return ;
	current = (*stack);
	*stack = current->prev;
	// while (1)
	// {
	// 	ra(stack);
	// 	if (current == *stack)
	// 		break ;
	// }
}

void	push_swap(t_stack **a, t_stack **b, int size, int algorithm ,double *disorder)
{
	if ((int)*disorder == 1)
	{
		invert(a);
		return ;
	}
	if (is_sorted(*a))
		return ;
	if (size <= 3)
	{
		simple_3low(a);
		return ;
	}
	if (size <= 5)
		simple_5low(a, b, size);
	else if (algorithm == 1)
		sort_simple(a, b, size);
	else if (algorithm == 2)
		sort_simple(a, b, size);
	else if (algorithm == 3)
	{
		ft_printf(1, "usando radix\n");
		radix_sort(a, b);
	}
	else
	{
		ft_printf(1, "usando radix\n");
		radix_sort(a, b);
	}
}
