/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 17:53:36 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/08 21:36:56 by guicarva         ###   ########.fr       */
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

double	compute_disorder(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;
	long	mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	current = stack;
	while (1)
	{
		next = current->next;
		while (next != stack)
		{
			total_pairs++;
			if (current->value > next->value)
				mistakes++;
			next = next->next;
		}
		if (current == stack->prev)
			break ;
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

void	create_stack(t_stack **stack, char **args, int *algorithm)
{
	t_stack	*new_node;
	int		i;
	long	n;

	i = -1;
	while (args[++i])
	{
		if (is_flags(args[i]))
		{
			*algorithm = set_flags(args[i], algorithm);
			if (*algorithm > 0)
			{
				i++;
				continue ;
			}
		}
		if (ft_atoi(args[i], &n))
			print_error_end_free_exit(stack, args);
		if (is_duplicate(*stack, n))
			print_error_end_free_exit(stack, args);
		new_node = ft_circular_newnode(n);
		if (!new_node)
			print_error_end_free_exit(stack, args);
		ft_circular_add_back(stack, new_node);
	}
}

t_stack	*ft_parse_args(int argc, char **argv, int *algorithm)
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
		create_stack(&stack, args, algorithm);
		free_args(args);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		algorithm;
	double	disorder;
	int		size;

	algorithm = 0;
	if (argc < 2)
		return (0);
	a = ft_parse_args(argc, argv, &algorithm);
	b = NULL;
	size = ft_stacksize(a);
	disorder = compute_disorder(a);
	assign_indexes(a);
	printf("disorder: %.2f%%\n", disorder * 100.0);
	ft_printf(1, "size: %i\n", size);
	ft_printf(1, "algorithm: %c\n\n", algorithm);
	push_swap(&a, &b, size, algorithm);
	ft_printf(1, "\n");
	print_list(a);
	print_list(b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
