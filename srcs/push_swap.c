/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhermefranca <guilhermefranca@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:57:59 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/11 18:39:26 by guilhermefr      ###   ########.fr       */
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
	int	size;

	size = ft_stacksize(*a);
	if (size <= 100 && bench->disorder * 100.0 < 20.0)
		sort_simple(a, b, bench);
	else
		bucket_sort(a, b, bench);
}

void	push_swap(t_stack **a, t_stack **b, t_bench *bench)
{
	int		size;

	if (!a || !*a || is_sorted(*a))
	{
		bench->disorder = 0.0;
		return ;
	}
	bench->disorder = compute_disorder(*a);
	size = ft_stacksize(*a);
	if (size <= 3)
		simple_3low(a, bench);
	else if (bench->algorithm == 2)
	{
		if (size <= 100)
			sort_simple(a, b, bench);
		else
			bucket_sort(a, b, bench);
	}
	else if (bench->algorithm == 3)
		bucket_sort(a, b, bench);
	else if (bench->algorithm == 4)
		bucket_sort(a, b, bench);
	else
		adaptive(a, b, bench);
}
