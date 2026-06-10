/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:45:17 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/10 20:51:35 by guilh            ###   ########.fr       */
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

void	radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = ft_stacksize(*a);
	max_bits = get_max_bits(*a);
	i = -1;
	while (++i < max_bits)
	{
		if (is_sorted(*a) && *b == NULL)
			break ;
		j = -1;
		while (++j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b, bench);
			else
				ra(a, bench);
		}
		while (*b != NULL)
			pa(a, b, bench);
	}
}
