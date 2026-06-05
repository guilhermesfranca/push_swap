/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:27:11 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/05 20:01:18 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	swap_move(t_stack **sa)
{
	swap(*sa);
}

void	swap(t_stack *top)
{
	int	tmp;

	if (!top || !top->next)
		return ;
	tmp = top->value;
	top->value = top->next->value;
	top->next->value = tmp;
}
