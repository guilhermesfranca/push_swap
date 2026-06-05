/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 17:53:36 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/05 19:11:10 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// double	compute_disorder(t_stack *a)
// {
// 	int	mistakes;
// 	int	total_pairs;
// 	int	size_a;
// 	int	i;
// 	int	j;

// 	mistakes = 0;
// 	total_pairs = 0;
// 	for i from 0 to size(a)-1:
// 	for j from i+1 to size(a)-1:
// 	total_pairs += 1
// 	if a[i] > a[j]:
// 	mistakes += 1
// 	return mistakes / total_pairs
// }

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

	algorithm = 0;
	if (argc < 2)
		return (0);
	sa = ft_parse_args(argc, argv, &algorithm);
	sb = NULL;
	ft_printf("algoritimo main: %i\n", algorithm);
	// swap_move(&sa);
	while (sa)
	{
		ft_printf("%i\n", sa->value);
		sa = sa->next;
	}
	return (0);
}
