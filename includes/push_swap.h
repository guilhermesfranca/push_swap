/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilh <guilh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:06:57 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/14 23:47:05 by guilh            ###   ########.fr       */
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
	int				active;
	int				algorithm;
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
void				print_bench(t_bench *bench);
double				compute_disorder(t_stack *stack);
void				free_args(char **args);
void				free_stack(t_stack **stack);
void				sa(t_stack **a, t_bench *bench);
void				print_error_end_free_exit(t_stack **sa, char **args);
void				set_flags(char *args, t_bench *bench);
int					is_flags(char *args);
int					ft_putnbr_f(double n, int fd);
int					ft_printf(int fd, const char *format, ...);
int					putchr(int c, int fd);
int					ft_putnbr_h(unsigned long nbr, char *base, int fd);
int					ft_putnbr_u(unsigned int n, int fd);
int					ft_putnbr(long n, int fd);
int					ft_putstr(char *s, int fd);
char				**ft_split(char const *s, char c);
int					get_index(t_stack *stack, int value);
void				assign_indexes(t_stack *stack);
void				create_stack(t_stack **stack, char **args, t_bench *bench);
t_stack				*ft_parse_args(int argc, char **argv, t_bench *bench);
int					is_sorted(t_stack *stack);
int					how_sorted(t_stack *stack);
void				adaptive(t_stack **a, t_stack **b, t_bench *bench);
void				push_swap(t_stack **a, t_stack **b, t_bench *bench);
int					ft_sqrt(int n);
void				push_to_b(t_stack **a, t_stack **b, t_bench *bench,
						int total_size);
void				push_to_a(t_stack **a, t_stack **b, t_bench *bench,
						int total_size);
void				k_sort(t_stack **a, t_stack **b, t_bench *bench);
int					get_max_bits(t_stack *a);
int					aaaa(t_stack *stack, int i);
void				radix_sort(t_stack **a, t_stack **b, t_bench *bench);
void				simple_3low(t_stack **stack, t_bench *bench);
void				bring_to_top(t_stack **stack, t_bench *bench,
						int target_index);
void				sort_simple(t_stack **a, t_stack **b, t_bench *bench);
int					get_min_pos(t_stack *stack);
int					get_max_pos(t_stack *stack);
int					get_target_b_pos(t_stack *b, int index_a);
int					get_target_a_pos(t_stack *a, int index_b);
void				rotate_single(t_stack **stack, int pos, int size, char name,
						t_bench *bench);
void				execute_cheapest_move(t_stack **a, t_stack **b, int pos_a,
						int pos_b, t_bench *bench);
void				find_and_move_cheapest(t_stack **a, t_stack **b,
						t_bench *bench);
void				turk_sort(t_stack **a, t_stack **b, t_bench *bench);
t_stack				*ft_circular_newnode(int value);
void				ft_circular_add_back(t_stack **lst, t_stack *new_node);
int					ft_stacksize(t_stack *stack);
int					is_duplicate(t_stack *stack, int n);
int					ft_atoi(const char *n_str, long *n);
char				*ft_substr(char const *s, unsigned int start, size_t size);
int					ft_strcmp(char *s1, char *s2);
size_t				ft_strlen(const char *s);
void				start_bench(t_bench *bench);
void				push_part2(t_stack **dest, t_stack *node_push);
void				push(t_stack **orin, t_stack **dest);
void				pa(t_stack **a, t_stack **b, t_bench *bench);
void				pb(t_stack **a, t_stack **b, t_bench *bench);
void				swap(t_stack **stack);
void				sb(t_stack **b, t_bench *bench);
void				ss(t_stack **a, t_stack **b, t_bench *bench);
void				rra(t_stack **a, t_bench *bench);
void				rrb(t_stack **b, t_bench *bench);
void				rrr(t_stack **a, t_stack **b, t_bench *bench);
void				ra(t_stack **a, t_bench *bench);
void				rb(t_stack **b, t_bench *bench);
void				rr(t_stack **a, t_stack **b, t_bench *bench);
#endif
