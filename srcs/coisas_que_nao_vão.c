/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coisas_que_nao_vão.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:21:09 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/10 18:53:46 by guilh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_bench(t_bench *bench)
{
	ft_printf(2, "[bench] disorder:  %f\n", bench->disorder * 100.0);
	ft_printf(2, "[bench] strategy:  %s\n", bench->strategy);
	ft_printf(2, "[bench] total_ops:  %i\n", bench->total_ops);
	ft_printf(2, "[bench] sa:  %i  sb:  %i  ss:  ", bench->sa, bench->sb);
	ft_printf(2, "%i  pa:  %i  pb:  %i\n", bench->ss, bench->pa, bench->pb);
	ft_printf(2, "[bench] ra:  %i  rb:  %i  rr:  ", bench->ra, bench->rb);
	ft_printf(2, "%i  rra:  %i  rrb:  %i", bench->rr, bench->rra, bench->rrb);
	ft_printf(2, "  rrr:  %i\n", bench->rrr);
}

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
		ft_printf(1, "value do prev: %i\n", current->prev->value);
		ft_printf(1, "Value: %i\n", current->value);
		ft_printf(1, "value do next: %i\n\n", current->next->value);
		current = current->next;
		if (current == stack)
			break ;
	}
}

double	compute_disorder(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;
	long	mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	current = stack;
	while (1)
	{
		next = current->next;
		while (next != stack)
		{
			total_pairs++;
			if (current->value > next->value)
				mistakes++;
			next = next->next;
		}
		if (current == stack->prev)
			break ;
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}
