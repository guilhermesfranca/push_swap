/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:22:16 by guilh             #+#    #+#             */
/*   Updated: 2026/06/18 23:07:19 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculate_actual_cost(int pos_a, int pos_b, int size_a, int size_b)
{
	int	cost_rr;
	int	cost_rrr;
	int	cost_mix1;
	int	cost_mix2;
	int	min;

	// Cenário 1: Ambos sobem (usando rr)
	if (pos_a > pos_b)
		cost_rr = pos_a;
	else
		cost_rr = pos_b;
	// Cenário 2: Ambos descem (usando rrr)
	if ((size_a - pos_a) > (size_b - pos_b))
		cost_rrr = size_a - pos_a;
	else
		cost_rrr = size_b - pos_b;
	// Cenários mistos
	cost_mix1 = pos_a + (size_b - pos_b);
	cost_mix2 = (size_a - pos_a) + pos_b;
	// Encontra o menor custo absoluto
	min = cost_rr;
	if (cost_rrr < min)
		min = cost_rrr;
	if (cost_mix1 < min)
		min = cost_mix1;
	if (cost_mix2 < min)
		min = cost_mix2;
	return (min);
}

void	exe_move_t(t_stack **a, t_stack **b, int *pos, t_bench *bench)
{
	int	size_a;
	int	size_b;
	int	pos_a;
	int	pos_b;

	size_a = ft_stacksize(*a);
	size_b = ft_stacksize(*b);
	pos_a = pos[0];
	pos_b = pos[1];
	// Se ambos estão na primeira metade, otimiza com RR
	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
	{
		while (pos_a > 0 && pos_b > 0)
		{
			rr(a, b, bench);
			pos_a--;
			pos_b--;
		}
	}
	// Se ambos estão na segunda metade, otimiza com RRR
	else if (pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		while (pos_a < size_a && pos_b < size_b)
		{
			rrr(a, b, bench);
			pos_a++;
			pos_b++;
		}
	}
	// Ajusta o restante individualmente e empurra
	rotate_single_a(a, pos_a, size_a, bench);
	rotate_single_b(b, pos_b, size_b, bench);
	pb(a, b, bench);
}

void	find_best_move(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*curr;
	int		pos_a;
	int		pos_b;
	int		min_ops;
	int		best_a;
	int		best_b;
	int		size_a;
	int		size_b;
	int		cost;
	int		pos_arr[2];

	curr = *a;
	pos_a = 0;
	min_ops = 2147483647;
	size_a = ft_stacksize(*a);
	size_b = ft_stacksize(*b);
	best_a = 0;
	best_b = 0;
	while (1)
	{
		pos_b = get_target_b_pos(*b, curr->index);
		cost = calculate_actual_cost(pos_a, pos_b, size_a, size_b);
		if (cost < min_ops)
		{
			min_ops = cost;
			best_a = pos_a;
			best_b = pos_b;
		}
		// Atalho de eficiência: custo 0 significa melhor movimento possível encontrado
		if (min_ops == 0)
			break ;
		pos_a++;
		curr = curr->next;
		if (curr == *a)
			break ;
	}
	pos_arr[0] = best_a;
	pos_arr[1] = best_b;
	exe_move_t(a, b, pos_arr, bench);
}

void	turk_sort_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	int	target_a;
	int	min_pos;

	if (ft_stacksize(*a) > 3)
		pb(a, b, bench);
	if (ft_stacksize(*a) > 3)
		pb(a, b, bench);
	while (ft_stacksize(*a) > 3)
		find_best_move(a, b, bench);
	simple_3low(a, bench);
	while (*b)
	{
		target_a = get_target_a_pos(*a, (*b)->index);
		rotate_single_a(a, target_a, ft_stacksize(*a), bench);
		pa(a, b, bench);
	}
	min_pos = get_min_pos(*a);
	rotate_single_a(a, min_pos, ft_stacksize(*a), bench);
}
