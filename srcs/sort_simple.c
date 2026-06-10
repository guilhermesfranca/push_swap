/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 11:00:25 by guilhermefr       #+#    #+#             */
/*   Updated: 2026/06/10 21:10:02 by guilh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simple_3low(t_stack **stack, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->value;
	mid = (*stack)->next->value;
	bot = (*stack)->next->next->value;
	if (top == bot || (bot > mid && bot > top))
	{
		if (top > mid)
			sa(stack, bench);
	}
	else if (top > mid && top > bot)
	{
		ra(stack, bench);
		if (mid > bot)
			sa(stack, bench);
	}
	else if (mid > top && mid > bot)
	{
		rra(stack, bench);
		if (bot > top)
			sa(stack, bench);
	}
}

void	bring_to_top(t_stack **stack, t_bench *bench, int target_index)
{
	int		pos;
	int		size;
	t_stack	*current;

	pos = 0;
	current = *stack;
	size = ft_stacksize(*stack);
	while (current->index != target_index)
	{
		pos++;
		current = current->next;
	}
	if (pos <= size / 2)
		while ((*stack)->index != target_index)
			ra(stack, bench);
	else
		while ((*stack)->index != target_index)
			rra(stack, bench);
}

void	sort_simple(t_stack **a, t_stack **b, t_bench *bench)
{
	int	current_index;
	int	remaining;

	if (!a || !*a || is_sorted(*a))
		return ;
	if (ft_stacksize(*a) == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a, bench);
		return ;
	}
	remaining = ft_stacksize(*a);
	current_index = 0;
	while (remaining > 3)
	{
		bring_to_top(a, bench, current_index);
		pb(b, a, bench);
		current_index++;
		remaining--;
	}
	simple_3low(a, bench);
	while (*b)
		pa(a, b, bench);
}
