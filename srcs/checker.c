/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 22:19:26 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/22 23:20:05 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	checker_execute_command(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		pa(a, b, NULL);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, NULL);
	else if (!ft_strcmp(line, "sa\n"))
		sa(a, NULL);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, NULL);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, NULL);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, NULL);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, NULL);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, NULL);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, NULL);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, NULL);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, NULL);
	else
		error_exit(a, b, NULL, line)
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv, NULL);
	b = NULL;
	assign_indexes(a);
	line = get_next_line(0);
	while (line)
	{
		checker_execute_command(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && !b)
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
