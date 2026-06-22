/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coisas_que_nao_vão.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:21:09 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/22 23:19:26 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_index(t_stack *stack, int value)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = stack;
	while (1)
	{
		if (current->value < value)
			index++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (index);
}

void	assign_indexes(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return ;
	current = stack;
	while (1)
	{
		current->index = get_index(stack, current->value);
		current = current->next;
		if (current == stack)
			break ;
	}
}
