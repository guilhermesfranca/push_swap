/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coisas_que_nao_vão.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:21:09 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/08 21:30:26 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return ;
	ft_printf(1, "LISTA:\n");
	current = stack;
	while (1)
	{
		// ft_printf(1, "Index: %i\n", current->index);
		// ft_printf(1, "value do prev: %i\n", current->prev->value);
		ft_printf(1, "Value: %i\n", current->value);
		// ft_printf(1, "value do next: %i\n\n", current->next->value);
		current = current->next;
		if (current == stack)
			break ;
	}
}
