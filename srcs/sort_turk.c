/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:22:16 by guilh             #+#    #+#             */
/*   Updated: 2026/06/15 20:38:43 by guicarva         ###   ########.fr       */
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

void	rotate_single(t_stack **stack, int pos, int size, char name, t_bench *bench)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			if (name == 'a')
				ra(stack, bench);
			else
				rb(stack, bench);
		}
	}
	else
	{
		while (pos++ < size)
		{
			if (name == 'a')
				rra(stack, bench);
			else
				rrb(stack, bench);
		}
	}
}

void	execute_cheapest_move(t_stack **a, t_stack **b, int pos_a, int pos_b, t_bench *bench)
{
	int	size_a;
	int	size_b;

	size_a = ft_stacksize(*a);
	size_b = ft_stacksize(*b);
	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
	{
		while (pos_a > 0 && pos_b > 0)
		{
			rr(a, b, bench);
			pos_a--;
			pos_b--;
		}
	}
	else if (pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		while (pos_a < size_a && pos_b < size_b)
		{
			rrr(a, b, bench);
			pos_a++;
			pos_b++;
		}
	}
	rotate_single(a, pos_a, size_a, 'a', bench);
	rotate_single(b, pos_b, size_b, 'b', bench);
	pb(a, b, bench);
}

void	find_and_move_cheapest(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*curr;
	int		size_a;
	int		size_b;
	int		pos_a;
	int		pos_b;
	int		best_a;
	int		best_b;
	int		min_ops;
	int		cost_a;
	int		cost_b;
	int		total_cost;

	curr = *a;
	pos_a = 0;
	min_ops = 2147483647;
	size_a = ft_stacksize(*a);
	size_b = ft_stacksize(*b);
	while (1)
	{
		pos_b = get_target_b_pos(*b, curr->index);
		if (pos_a <= size_a / 2)
			cost_a = pos_a;
		else
			cost_a = size_a - pos_a;
		if (pos_b <= size_b / 2)
			cost_b = pos_b;
		else
			cost_b = size_b - pos_b;
		if ((pos_a <= size_a / 2 && pos_b <= size_b / 2) || (pos_a > size_a / 2 && pos_b > size_b / 2))
		{
			if (cost_a > cost_b)
				total_cost = cost_a;
			else
				total_cost = cost_b;
		}
		else
			total_cost = cost_a + cost_b;
		if (total_cost < min_ops)
		{
			min_ops = total_cost;
			best_a = pos_a;
			best_b = pos_b;
		}
		pos_a++;
		curr = curr->next;
		if (curr == *a)
			break ;
	}
	execute_cheapest_move(a, b, best_a, best_b, bench);
}

void	turk_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	target_a;
	int	min_pos;

	if (!a || !*a || is_sorted(*a))
		return ;
	if (ft_stacksize(*a) > 3)
		pb(a, b, bench);
	if (ft_stacksize(*a) > 3)
		pb(a, b, bench);
	while (ft_stacksize(*a) > 3)
		find_and_move_cheapest(a, b, bench);
	simple_3low(a, bench);
	while (*b)
	{
		target_a = get_target_a_pos(*a, (*b)->index);
		rotate_single(a, target_a, ft_stacksize(*a), 'a', bench);
		pa(a, b, bench);
	}
	min_pos = get_min_pos(*a);
	rotate_single(a, min_pos, ft_stacksize(*a), 'a', bench);
}
