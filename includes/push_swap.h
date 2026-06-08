/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:06:57 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/07 16:44:50 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_bench
{
	double			disorder;
	char			*strategy;
	char			*complexity;
	int				total_ops;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_bench;

/* autoheaders */
int					is_sorted(t_stack *stack);
void				simple_3low(t_stack **a);
void				bring_to_top(t_stack **a, int target_index, int size);
void				simple_5low(t_stack **a, t_stack **b, int size);
void				sort_simple(t_stack **a, t_stack **b, int size);
void				free_args(char **args);
void				free_stack(t_stack **stack);
void				sa(t_stack **a);
void				print_error_end_free_exit(t_stack **sa, char **args);
int					is_duplicate(t_stack *stack, int n);
int					set_flags(char *args, int *algorithm);
int					is_flags(char *args);
int					ft_atoi(const char *n_str, long *n);
char				*ft_substr(char const *s, unsigned int start, size_t size);
int					ft_strcmp(char *s1, char *s2);
size_t				ft_strlen(const char *s);
int					ft_printf(int fd, const char *format, ...);
int					ft_putnbr_p(unsigned long nbr, int fd);
int					ft_putnbr_h(unsigned int nbr, char *base, int fd);
int					ft_putnbr_u(unsigned int n, int fd);
int					ft_putnbr(long n, int fd);
int					ft_putstr(char *s, int fd);
char				**ft_split(char const *s, char c);
int					get_index(t_stack *stack, int value);
void				assign_indexes(t_stack *stack);
double				compute_disorder(t_stack *stack);
void				create_stack(t_stack **stack, char **args, int *algorithm);
t_stack				*ft_parse_args(int argc, char **argv, int *algorithm);
void				push(t_stack **orin, t_stack **dest);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				pa(t_stack **b, t_stack **a);
void				pb(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				swap(t_stack **stack);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				invert(t_stack **stack);
void				push_swap(t_stack **a, t_stack **b, int size, int algorithm,
						double *disorder);
t_stack				*ft_circular_newnode(int value);
void				ft_circular_add_back(t_stack **lst, t_stack *new_node);
int					ft_stacksize(t_stack *stack);
void				print_list(t_stack *stack);
int					get_max_bits(int max_index);
void				radix_sort(t_stack **a, t_stack **b);
#endif
