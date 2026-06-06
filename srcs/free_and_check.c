/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:37:50 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/06 10:55:02 by guicarva         ###   ########.fr       */
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
	write(2, "Error\n", 6);
	exit(1);
}

int	is_duplicate(t_stack *sa, int n)
{
	while (sa)
	{
		if (sa->value == n)
			return (1);
		sa = sa->next;
	}
	return (0);
}

int	is_flags(char *args)
{
	if (!ft_strcmp(args, "--simple"))
		return (1);
	if (!ft_strcmp(args, "--medium"))
		return (2);
	if (!ft_strcmp(args, "--complex"))
		return (3);
	if (!ft_strcmp(args, "--adaptive"))
		return (4);
	return (0);
}
