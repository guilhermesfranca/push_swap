/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranca <gfranca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:58:47 by gfranca           #+#    #+#             */
/*   Updated: 2026/06/06 17:58:48 by gfranca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simple(t_stack **sa)
{
	t_stack	*top;
	t_stack	*mid;
	t_stack	*bot;

	top = *sa;
	mid = top->next;
	bot = top->next->next;
	if (bot == NULL && top->value > mid->value)
		return (swap(sa));
	else if (bot == NULL)
		return ;
	if (top->value < mid->value && mid->value > bot->value
		&& top->value < bot->value)
		return (rotate_r(sa), swap(sa));
	if (top->value > mid->value && mid->value < bot->value
		&& top->value < bot->value)
		return (swap(sa));
	if (top->value < mid->value && mid->value > bot->value
		&& top->value > bot->value)
		return (rotate_r(sa));
	if (top->value > mid->value && mid->value > bot->value)
		return (swap(sa), rotate_r(sa));
	if (top->value > mid->value && mid->value < bot->value
		&& top->value > bot->value)
		return (rotate(sa));
}
