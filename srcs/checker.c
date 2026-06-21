/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 22:19:26 by guilh             #+#    #+#             */
/*   Updated: 2026/06/21 22:47:49 by guilh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **a, t_stack **b, int flag)
{
	if ((*a)->prev == *a || (*b)->prev == *b)
		return ;
	if (flag == 'r')
	{
		if (*a)
			*a = (*a)->prev;
		if (*b)
			*b = (*b)->prev;
	}
	else
	{
		if (*a)
			*a = (*a)->next;
		if (*b)
			*b = (*b)->next;
	}
}

static void    checker_execute_command(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "Error\n"))
	{
		free(line);
		print_error_end_free_exit(a, b, NULL);
	}
	if (ft_strcmp(line, "pa\n"))
		pa(a, b, 0);
	if (ft_strcmp(line, "pb\n"))
		pb(a, b, 0);
	if (ft_strcmp(line, "sa\n") || ft_strcmp(line, "ss\n"))
		swap(a);
	if (ft_strcmp(line, "sb\n") || ft_strcmp(line, "ss\n"))
		swap(b);
	if (ft_strcmp(line, "ra\n") || ft_strcmp(line, "rr\n"))
		rotate(a, b, 0);
	if (ft_strcmp(line, "rb\n") || ft_strcmp(line, "rr\n"))
		rotate(a, b, 0);
	if (ft_strcmp(line, "rra\n") || ft_strcmp(line, "rrr\n"))
		rotate(a, b, 'r');
	if (ft_strcmp(line, "rrb\n") || ft_strcmp(line, "rrr\n"))
		rotate(a, b, 'r');

}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char    *line;

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
	return (0);
}
