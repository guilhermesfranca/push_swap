/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranca <gfranca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 17:53:36 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/06 17:46:44 by gfranca          ###   ########.fr       */
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

void	create_stack(t_stack **sa, char **args, int *result)
{
	t_stack	*new_node;
	long	n;
	int		i;
	int		exit;

	i = 0;
	while (args[i])
	{
		exit = is_flags(args[i]);
		if (exit)
		{
			if (*result != 0)
				print_error_end_free_exit(sa, args);
			*result = exit;
			i++;
			continue ;
		}
		if (ft_atoi(args[i], &n))
			print_error_end_free_exit(sa, args);
		if (is_duplicate(*sa, n))
			print_error_end_free_exit(sa, args);
		new_node = ft_stacknew(n);
		ft_stackadd_back(&*sa, new_node);
		i++;
	}
}

t_stack	*ft_parse_args(int argc, char **argv, int *algorithm)
{
	char	**args;
	t_stack	*sa;
	int		i;
	int		result;

	sa = NULL;
	i = 1;
	result = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			print_error_end_free_exit(&sa, NULL);
		args = ft_split(argv[i], ' ');
		if (!args || !args[0])
			print_error_end_free_exit(&sa, args);
		create_stack(&sa, args, &result);
		if (*algorithm == 0 && result != 0)
			*algorithm = result;
		free_args(args);
		i++;
	}
	return (sa);
}

int	main(int argc, char **argv)
{
	t_stack	*sa;
	t_stack	*sb;
	int		algorithm;
	int		size;
	double	disorder;

	algorithm = 0;
	if (argc < 2)
		return (0);
	sa = ft_parse_args(argc, argv, &algorithm);
	sb = NULL;
	size = ft_stacksize(sa);
	disorder = compute_disorder(sa);
	assign_indexes(sa);
	printf("%.2f%%\n", disorder * 100.0);
	simple(&sa);
	ft_printf(1, "LISTA 1:\n");
	while (sa)
	{
		ft_printf(1, "value: %i\n", sa->value);
		sa = sa->next;
	}
	return (0);
}
