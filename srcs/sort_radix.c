/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:45:17 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/15 22:47:54 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_bits(t_stack *a)
{
	t_stack	*current;
	int		max_index;
	int		bits;

	if (!a)
		return (0);
	max_index = a->index;
	current = a;
	while (1)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
		if (current->next == a)
			break ;
	}
	bits = 0;
	while ((max_index >> bits) > 0)
		bits++;
	return (bits);
}

int	aaaa(t_stack *stack, int i)
{
	t_stack	*curr;
	int		one;
	int		zero;

	curr = stack;
	one = 0;
	zero = 0;
	while (1)
	{
		if (((curr->index >> i) & 1) == 1)
			one++;
		else
			zero++;
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	if (one == 0 || zero == 0)
		return (1);
	return (0);
}

void	radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = ft_stacksize(*a);
		if (aaaa(*a, i))
		{
			i++;
			continue ;
		}
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b, bench);
			else
				ra(a, bench);
			j++;
		}
		j = 0;
		size = ft_stacksize(*b);
		if (aaaa(*b, i + 1))
		{
			i++;
			continue ;
		}
		while (j < size)
		{
			if (((*b)->index >> (i + 1) & 1) == 1)
				pa(a, b, bench);
			else
				rb(b, bench);
			j++;
		}
		i++;
	}
	while (*b)
		pa(a, b, bench);
}
