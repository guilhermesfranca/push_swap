/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranca <gfranca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:06:57 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/06 17:35:58 by gfranca          ###   ########.fr       */
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
int					ft_printf(int fd, const char *format, ...);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t size);
int					ft_atoi(const char *n_str, long *n);
t_stack				*ft_stacknew(int value);
t_stack				*ft_stacklast(t_stack *lst);
void				ft_stackadd_back(t_stack **lst, t_stack *new_node);
int					ft_stacksize(t_stack *lst);
void				free_args(char **args);
void				free_stack(t_stack **stack);
void				sa(t_stack **sa);
void				print_error_end_free_exit(t_stack **sa, char **args);
int					is_duplicate(t_stack *sa, int n);
int					is_flags(char *args);
int					ft_strcmp(char *s1, char *s2);
int					ft_putnbr_p(unsigned long nbr, int fd);
int					ft_putnbr_h(unsigned int nbr, char *base, int fd);
int					ft_putnbr_u(unsigned int n, int fd);
int					ft_putnbr(long n, int fd);
int					ft_putstr(char *s, int fd);
void				simple(t_stack **sa);
int					get_index(t_stack *stack, int value);
void				assign_indexes(t_stack *stack);
double				compute_disorder(t_stack *sa);
void				create_stack(t_stack **sa, char **args, int *result);
t_stack				*ft_parse_args(int argc, char **argv, int *algorithm);
void				swap(t_stack **top);
void				sb(t_stack **sb);
void				ss(t_stack **sa, t_stack **sb);
void				push(t_stack **dest, t_stack **origin);
void				pb(t_stack **sa, t_stack **sb);
void				rotate(t_stack **top);
void				ra(t_stack **sa);
void				rb(t_stack **sb);
void				rr(t_stack **sa, t_stack **sb);
void				pa(t_stack **sa, t_stack **sb);
void				rotate_r(t_stack **top);
void				rra(t_stack **sa);
void				rrb(t_stack **sb);
void				rrr(t_stack **sa, t_stack **sb);
#endif
