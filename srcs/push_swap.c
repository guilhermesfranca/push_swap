/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:57:59 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/18 23:08:16 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack || stack->next == stack)
		return (1);
	current = stack;
	while (1)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
		if (current->next == stack)
			break ;
	}
	return (1);
}

int	how_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack || stack->next == stack)
		return (1);
	current = stack;
	while (1)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
		if (current->next == stack)
			break ;
	}
	return (1);
}

void	adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	if (bench->disorder < 0.2)
		turk_sort(a, b, bench);
	else if (bench->disorder < 0.5)
		k_sort(a, b, bench);
	else
		turk_sort_complex(a, b, bench);
}

void	push_swap(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	if (!a || !*a || is_sorted(*a))
	{
		bench->disorder = 0.0;
		return ;
	}
	size = ft_stacksize(*a);
	if (size <= 3)
		simple_3low(a, bench);
	else if (size <= 5)
		sort_simple(a, b, bench);
	else if (bench->algorithm == 1)
		turk_sort(a, b, bench);
	else if (bench->algorithm == 2)
		k_sort(a, b, bench);
	else if (bench->algorithm == 3)
		turk_sort_complex(a, b, bench);
	else
		adaptive(a, b, bench);
}
