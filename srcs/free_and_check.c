/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:37:50 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/09 23:24:49 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next_node;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	if (tmp->prev)
		tmp->prev->next = NULL;
	while (tmp)
	{
		next_node = tmp->next;
		free(tmp);
		tmp = next_node;
	}
	*stack = NULL;
}

void	print_error_end_free_exit(t_stack **sa, char **args)
{
	if (args)
		free_args(args);
	if (sa && *sa)
		free_stack(sa);
	ft_printf(2, "Error\n");
	exit(1);
}

int	is_duplicate(t_stack *stack, int n)
{
	t_stack	*current;

	if (!stack)
		return (0);
	current = stack;
	while (1)
	{
		if (current->value == n)
			return (1);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (0);
}

void	set_flags(char *args, t_bench *bench)
{
	if (!ft_strcmp(args, "--simple"))
		bench->strategy = "Adaptive / O(n"")";
	else if (!ft_strcmp(args, "--medium"))
	else if (!ft_strcmp(args, "--complex"))
	else if (!ft_strcmp(args, "--adaptive"))
}

int	is_flags(char *args)
{
	if (!ft_strcmp(args, "--simple"))
		return (1);
	if (!ft_strcmp(args, "--medium"))
		return (1);
	if (!ft_strcmp(args, "--complex"))
		return (1);
	if (!ft_strcmp(args, "--adaptive"))
		return (1);
	if (!ft_strcmp(args, "--bench"))
		return (1);
	return (0);
}

