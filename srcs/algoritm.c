/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 11:00:25 by guilhermefr       #+#    #+#             */
/*   Updated: 2026/06/08 22:46:59 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack || stack->next == stack)
		return (1);
	current = stack;
	while (current->next != stack)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}


void	simple_3low(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top == bot || (bot > mid && bot > top))
	{
		if (top > mid)
			sa(a);
	}
	else if (top > mid && top > bot)
	{
		ra(a);
		if (mid > bot)
			sa(a);
	}
	else if (mid > top && mid > bot)
	{
		rra(a);
		if (bot > top)
			sa(a);
	}
}

void	bring_to_top(t_stack **a, int target_index, int size)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = *a;
	while (tmp->index != target_index)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
		while ((*a)->index != target_index)
			ra(a);
	else
		while ((*a)->index != target_index)
			rra(a);
}

void	simple_5low(t_stack **a, t_stack **b, int size)
{
	if (size == 5)
	{
		bring_to_top(a, 0, size);
		pb(a, b);
		bring_to_top(a, 1, size);
		pb(a, b);
		simple_3low(a);
		pa(a, b);
		pa(a, b);
	}
	else
	{
		bring_to_top(a, 0, size);
		pb(a, b);
		simple_3low(a);
		pa(a, b);
	}
}

void	sort_simple(t_stack **a, t_stack **b, int size)
{
	int	current_index;
	int	remaining;

	remaining = size;
	current_index = 0;
	while (remaining > 3)
	{
		bring_to_top(a, current_index, size);
		pb(a, b);
		current_index++;
		remaining--;
	}
	simple_3low(a);
	while (*b)
		pa(a, b);
}
