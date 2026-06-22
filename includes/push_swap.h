/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:06:57 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/22 23:22:31 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef A
#  define A 0
# endif

# ifndef B
#  define B 1
# endif

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
int					putchr(int c, int fd);
int					ft_putnbr_h(unsigned long nbr, char *base, int fd);
int					ft_putnbr_u(unsigned int n, int fd);
int					ft_putnbr(long n, int fd);
int					ft_putstr(char *s, int fd);
char				**ft_split(char const *s, char c);
int					get_min_pos(t_stack *stack);
int					get_max_pos(t_stack *stack);
int					get_target_b_pos(t_stack *b, int index_a);
int					get_target_a_pos(t_stack *a, int index_b);
void				rotate_single_a(t_stack **a, int pos_a, int size_a,
						t_bench *bench);
void				rotate_single_b(t_stack **b, int pos_b, int size_b,
						t_bench *bench);
void				execute_move(t_stack **a, t_stack **b, int *best,
						t_bench *bench);
int					ft_putnbr_f(double n, int fd);
int					ft_printf(int fd, const char *format, ...);
void				k_sort(t_stack **a, t_stack **b, t_bench *bench);
void				simple_3low(t_stack **stack, t_bench *bench);
void				sort_simple(t_stack **a, t_stack **b, t_bench *bench);
int					ft_atoi(const char *n_str, long *n);
int					ft_strcmp(char *s1, char *s2);
t_stack				*ft_circular_newnode(int value);
void				ft_circular_add_back(t_stack **lst, t_stack *new_node);
int					ft_stacksize(t_stack *stack);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_join_free(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				start_bench(t_bench *bench);
void				print_bench(t_bench *bench);
void				push_swap(t_stack **a, t_stack **b, t_bench *bench);
int					get_index(t_stack *stack, int value);
void				assign_indexes(t_stack *stack);
void				free_args(char **args);
void				free_stack(t_stack **stack);
void				error_exit(t_stack **a, t_stack **b, char **args,
						char *line);
int					is_sorted(t_stack *stack);
int					is_duplicate(t_stack *stack, int n);
char				*get_next_line(int fd);
double				compute_disorder(t_stack *stack);
void				create_stack(t_stack **stack, char **args, t_bench *bench);
t_stack				*parse_args(int argc, char **argv, t_bench *bench);
void				pa(t_stack **a, t_stack **b, t_bench *bench);
void				pb(t_stack **a, t_stack **b, t_bench *bench);
void				ra(t_stack **a, t_bench *bench);
void				rb(t_stack **b, t_bench *bench);
void				rr(t_stack **a, t_stack **b, t_bench *bench);
void				rra(t_stack **a, t_bench *bench);
void				rrb(t_stack **b, t_bench *bench);
void				rrr(t_stack **a, t_stack **b, t_bench *bench);
void				swap(t_stack **stack);
void				sa(t_stack **a, t_bench *bench);
void				sb(t_stack **b, t_bench *bench);
void				ss(t_stack **a, t_stack **b, t_bench *bench);
void				turk_sort(t_stack **a, t_stack **b, t_bench *bench);
void				radix_sort(t_stack **a, t_stack **b, t_bench *bench);
#endif
