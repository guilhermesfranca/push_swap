/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:57:59 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/09 23:17:49 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	adaptive(t_stack **a, t_stack **b, double disorder)
{
	if (disorder < 0.2)
		sort_simple(a, b);
	else if (disorder < 0.5)
		bucket_sort(a, b);
	else
		radix_sort(a, b);
}

void	push_swap(t_stack **a, t_stack **b, t_bench *bench)
{
	double	disorder;
	int		size;

	disorder = compute_disorder(*a);
	size = ft_stacksize(*a);
	if (is_sorted(*a))
		return ;
	else if (size <= 3)
		simple_3low(a);
	else if (size <= 5)
		simple_5low(a, b);
	// else if (algorithm == 's')
	// 	radix_sort(a, b);
	// else if (algorithm == 'm')
	// 	bucket_sort(a, b);
	// else if (algorithm == 'c')
// 		radix_sort(a, b);
	// else
	// 	adaptive(a, b, disorder);
}
