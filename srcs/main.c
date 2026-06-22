/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 17:53:36 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/22 23:13:48 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;

	if (argc < 2)
		return (0);
	start_bench(&bench);
	a = parse_args(argc, argv, &bench);
	b = NULL;
	bench.disorder = compute_disorder(a) * 100.0;
	if (!bench.algorithm && bench.disorder < 20.0)
		bench.strategy = "Adaptive / O(n²)";
	else if (!bench.algorithm && bench.disorder < 50.0)
		bench.strategy = "Adaptive / O(n√n)";
	else if (!bench.algorithm && bench.disorder >= 50.0)
		bench.strategy = "Adaptive / O(n log n)";
	assign_indexes(a);
	push_swap(&a, &b, &bench);
	if (bench.active)
		print_bench(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
