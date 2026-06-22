/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:57:59 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/22 23:22:11 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	start_bench(t_bench *bench)
{
	bench->disorder = 0.0;
	bench->active = 0;
	bench->algorithm = 0;
	bench->strategy = "Adaptive";
	bench->total_ops = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

void	print_bench(t_bench *bench)
{
	ft_printf(2, "[bench] disorder:  %f%%\n", bench->disorder);
	ft_printf(2, "[bench] strategy:  %s\n", bench->strategy);
	ft_printf(2, "[bench] total_ops:  %i\n", bench->total_ops);
	ft_printf(2, "[bench] sa:  %i  sb:  %i  ss:  ", bench->sa, bench->sb);
	ft_printf(2, "%i  pa:  %i  pb:  %i\n", bench->ss, bench->pa, bench->pb);
	ft_printf(2, "[bench] ra:  %i  rb:  %i  rr:  ", bench->ra, bench->rb);
	ft_printf(2, "%i  rra:  %i  rrb:  %i", bench->rr, bench->rra, bench->rrb);
	ft_printf(2, "  rrr:  %i\n", bench->rrr);
}

static void	adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	if (bench->disorder < 20.0)
		turk_sort(a, b, bench);
	else if (bench->disorder < 50.0)
		k_sort(a, b, bench);
	else
		radix_sort(a, b, bench);
}

void	push_swap(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = ft_stacksize(*a);
	if (size <= 3)
		simple_3low(a, bench);
	else if (size <= 5 || bench->disorder == 100.0)
		sort_simple(a, b, bench);
	else if (bench->algorithm == 1)
		turk_sort(a, b, bench);
	else if (bench->algorithm == 2)
		k_sort(a, b, bench);
	else if (bench->algorithm == 3)
		radix_sort(a, b, bench);
	else
		adaptive(a, b, bench);
}
