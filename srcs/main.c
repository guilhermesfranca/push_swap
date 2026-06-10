/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 17:53:36 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/10 21:16:23 by guilh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	get_index(t_stack *stack, int value)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = stack;
	while (1)
	{
		if (current->value < value)
			index++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (index);
}

void	assign_indexes(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return ;
	current = stack;
	while (1)
	{
		current->index = get_index(stack, current->value);
		current = current->next;
		if (current == stack)
			break ;
	}
}

void	create_stack(t_stack **stack, char **args, t_bench *bench)
{
	t_stack	*new_node;
	int		i;
	long	n;

	i = 0;
	while (args[i])
	{
		if (is_flags(args[i]))
		{
			set_flags(args[i], bench);
			i++;
			continue ;
		}
		if (ft_atoi(args[i], &n))
			print_error_end_free_exit(stack, args);
		if (is_duplicate(*stack, n))
			print_error_end_free_exit(stack, args);
		new_node = ft_circular_newnode(n);
		if (!new_node)
			print_error_end_free_exit(stack, args);
		ft_circular_add_back(stack, new_node);
		i++;
	}
}

t_stack	*ft_parse_args(int argc, char **argv, t_bench *bench)
{
	t_stack	*stack;
	char	**args;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			print_error_end_free_exit(&stack, NULL);
		args = ft_split(argv[i], ' ');
		if (!args || !args[0])
			print_error_end_free_exit(&stack, args);
		create_stack(&stack, args, bench);
		free_args(args);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;

	if (argc < 2)
		return (0);
	start_bench(&bench);
	a = ft_parse_args(argc, argv, &bench);
	assign_indexes(a);
	b = NULL;
	push_swap(&a, &b, &bench);
	print_bench(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
