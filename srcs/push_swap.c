/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhermefranca <guilhermefranca@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:57:59 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/07 12:38:45 by guilhermefr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack **a, t_stack **b, int size, int algorithm)
{
	if (is_sorted(*a))
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	if (size == 3)
	{
		simple_3low(a);
		return ;
	}
	if (size <= 5)
		simple_5low(a, b, size);
	else if (algorithm == 1)
		sort_simple(a, b, size);
	else if (algorithm == 2)
		sort_simple(a, b, size);
	else if (algorithm == 3)
		sort_simple(a, b, size);
	else
		sort_simple(a, b, size);
}
