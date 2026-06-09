/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:02:25 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/09 22:20:18 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_b(t_stack **a, t_stack **b, int total_size)
{
	int	size_bucket;
	int	i;

	size_bucket = ((ft_sqrt(total_size) * 3) / 2);
	i = 0;
	while (a != NULL)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			if (*b < (*b)->next)
				rb(b);
			i++;
		}
		else if ((*a)->index <= i + size_bucket)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
		{
			ra(a);
			i++;
		}
	}
}

void	bucket_sort(t_stack **a, t_stack **b)
{
	int	total_size;

	total_size = ft_stacksize(*a);
	push_to_b(a, b, total_size);
}
