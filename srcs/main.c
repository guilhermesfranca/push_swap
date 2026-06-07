/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhermefranca <guilhermefranca@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 17:53:36 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/07 12:41:39 by guilhermefr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	get_index(t_stack *stack, int value)
{
	t_stack	*tmp;
	int		index;

	index = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value < value)
			index++;
		tmp = tmp->next;
	}
	return (index);
}

void	assign_indexes(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		tmp->index = get_index(stack, tmp->value);
		tmp = tmp->next;
	}
}

double	compute_disorder(t_stack *sa)
{
	t_stack	*cur;
	t_stack	*next;
	long	mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	cur = sa;
	while (cur)
	{
		next = cur->next;
		while (next)
		{
			total_pairs++;
			if (cur->value > next->value)
				mistakes++;
			next = next->next;
		}
		cur = cur->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

void	create_stack(t_stack **stack, char **args, int *result)
{
	t_stack	*new_node;
	int		exit;
	int		i;
	long	n;

	i = 0;
	while (args[i])
	{
		exit = is_flags(args[i]);
		if (exit)
		{
			if (*result != 0)
				print_error_end_free_exit(stack, args);
			*result = exit;
			i++;
			continue ;
		}
		if (ft_atoi(args[i], &n))
			print_error_end_free_exit(stack, args);
		if (is_duplicate(*stack, n))
			print_error_end_free_exit(stack, args);
		new_node = ft_stacknew(n);
		ft_stackadd_back(&*stack, new_node);
		i++;
	}
}

t_stack	*ft_parse_args(int argc, char **argv, int *algorithm)
{
	t_stack	*stack;
	char	**args;
	int		result;
	int		i;

	stack = NULL;
	result = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			print_error_end_free_exit(&stack, NULL);
		args = ft_split(argv[i], ' ');
		if (!args || !args[0])
			print_error_end_free_exit(&stack, args);
		create_stack(&stack, args, &result);
		if (*algorithm == 0 && result != 0)
			*algorithm = result;
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
	int		size;

	// double	disorder;
	algorithm = 0;
	if (argc < 2)
		return (0);
	a = ft_parse_args(argc, argv, &algorithm);
	b = NULL;
	size = ft_stacksize(a);
	// disorder = compute_disorder(a);
	assign_indexes(a);
	// printf("%.2f%%\n", disorder * 100.0);
	push_swap(&a, &b, size, algorithm);
	// ft_printf(1, "LISTA 1:\n");
	// while (a)
	// {
	// 	ft_printf(1, "value: %i\n", a->value);
	// 	a = a->next;
	// }
	// ft_printf(1, "LISTA 2:\n");
	// while (b)
	// {
	// 	ft_printf(1, "value: %i\n", b->value);
	// 	b = b->next;
	// }
	free_stack(&a);
	free_stack(&b);
	return (0);
}
