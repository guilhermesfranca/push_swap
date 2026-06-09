/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranca <gfranca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:57:59 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/09 20:59:32 by gfranca          ###   ########.fr       */
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

void	push_swap(t_stack **a, t_stack **b, int size, int algorithm, double disorder)
{
	// if ((int)*disorder == 1)
	// {
	// 	invert(a);
	// 	return ;
	// }
	if (is_sorted(*a))
		return ;
	if (size <= 3)
	{
		simple_3low(a);
		return ;
	}
	if (size <= 5)
		simple_5low(a, b, size);
	else if (algorithm == 's')
		radix_sort(a, b);
	else if (algorithm == 'm')
		radix_sort(a, b);
	else if (algorithm == 'c')
	{
		// ft_printf(1, "usando radix\n");
		radix_sort(a, b);
	}
	else
	{
		if (disorder < 0.2)
			sort_simple(a, b, size);
		else if (disorder < 0.5)
			radix_sort(a, b); // chunk sort
		else
			radix_sort(a, b);
	}
}
