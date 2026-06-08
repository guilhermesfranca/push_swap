/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:45:17 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/08 21:00:51 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while ((max_index >> bits) > 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = ft_stacksize(*a);
	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i & 1) == 0)
				pb(b, a);
			else
				ra(a);
			j++;
		}
		while (*b != NULL)
			pa(a, b);
		i++;
	}
}
