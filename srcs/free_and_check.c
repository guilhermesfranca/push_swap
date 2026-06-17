/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:37:50 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/17 22:56:38 by guilh            ###   ########.fr       */
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

void	set_flags(char *args, t_bench *bench)
{
	if (!ft_strcmp(args, "--simple"))
	{
		bench->algorithm = 1;
		bench->strategy = "Simple / O(n²)";
	}
	else if (!ft_strcmp(args, "--medium"))
	{
		bench->algorithm = 2;
		bench->strategy = "Medium / O(n\u221An)";
	}
	else if (!ft_strcmp(args, "--complex"))
	{
		bench->algorithm = 3;
		bench->strategy = "Complex / O(n log n)";
	}
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

