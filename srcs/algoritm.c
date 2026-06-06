/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:58:47 by gfranca           #+#    #+#             */
/*   Updated: 2026/06/06 20:14:56 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	simple(t_stack **sa)
// {
// 	t_stack	*top;
// 	t_stack	*mid;
// 	t_stack	*bot;

// 	top = *sa;
// 	mid = top->next;
// 	bot = top->next->next;
// 	if (bot == NULL && top->value > mid->value)
// 		return (swap(sa));
// 	else if (bot == NULL)
// 		return ;
// 	if (top->value < mid->value && mid->value > bot->value
// 		&& top->value < bot->value)
// 		return (rotate_r(sa), swap(sa));
// 	if (top->value > mid->value && mid->value < bot->value
// 		&& top->value < bot->value)
// 		return (swap(sa));
// 	if (top->value < mid->value && mid->value > bot->value
// 		&& top->value > bot->value)
// 		return (rotate_r(sa));
// 	if (top->value > mid->value && mid->value > bot->value)
// 		return (swap(sa), rotate_r(sa));
// 	if (top->value > mid->value && mid->value < bot->value
// 		&& top->value > bot->value)
// 		return (rotate(sa));
// }

void	simple_3low(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && top > bot)
	{
		ra(a);
		if (mid > bot)
			sa(a);
	}
	else if (mid > top && mid > bot)
	{
		rra(a);
		if (bot > top)
			sa(a);
	}
	if (top > mid)
		sa(a);
}
