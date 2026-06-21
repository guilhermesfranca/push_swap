/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coisas_que_nao_vão.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:21:09 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/21 22:56:05 by guilh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	how_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack || stack->next == stack)
		return (1);
	current = stack;
	while (1)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
		if (current->next == stack)
			break ;
	}
	return (1);
}

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
