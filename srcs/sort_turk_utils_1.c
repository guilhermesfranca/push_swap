/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 21:30:10 by guilh             #+#    #+#             */
/*   Updated: 2026/06/16 23:00:47 by guilh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_pos(t_stack *stack)
{
	t_stack	*curr;
	int		min_val;
	int		min_pos;
	int		pos;

	if (!stack)
		return (0);
	curr = stack;
	min_val = curr->index;
	min_pos = 0;
	pos = 0;
	while (1)
	{
		if (curr->index < min_val)
		{
			min_val = curr->index;
			min_pos = pos;
		}
		pos++;
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (min_pos);
}

int	get_max_pos(t_stack *stack)
{
	t_stack	*curr;
	int		max_val;
	int		max_pos;
	int		pos;

	if (!stack)
		return (0);
	curr = stack;
	max_val = curr->index;
	max_pos = 0;
	pos = 0;
	while (1)
	{
		if (curr->index > max_val)
		{
			max_val = curr->index;
			max_pos = pos;
		}
		pos++;
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (max_pos);
}

int	get_target_b_pos(t_stack *b, int index_a)
{
	t_stack	*curr;
	int		pos;
	int		target_pos;
	long	closest_smaller;

	curr = b;
	pos = 0;
	target_pos = 0;
	closest_smaller = -2147483649LL;
	while (1)
	{
		if (curr->index < index_a && curr->index > closest_smaller)
		{
			closest_smaller = curr->index;
			target_pos = pos;
		}
		pos++;
		curr = curr->next;
		if (curr == b)
			break ;
	}
	if (closest_smaller == -2147483649LL)
		return (get_max_pos(b));
	return (target_pos);
}

int	get_target_a_pos(t_stack *a, int index_b)
{
	t_stack	*curr;
	int		pos;
	int		target_pos;
	long	closest_bigger;

	curr = a;
	pos = 0;
	target_pos = 0;
	closest_bigger = 2147483648LL;
	while (1)
	{
		if (curr->index > index_b && curr->index < closest_bigger)
		{
			closest_bigger = curr->index;
			target_pos = pos;
		}
		pos++;
		curr = curr->next;
		if (curr == a)
			break ;
	}
	if (closest_bigger == 2147483648LL)
		return (get_min_pos(a));
	return (target_pos);
}
