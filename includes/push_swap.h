/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:06:57 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/05 11:38:17 by guicarva         ###   ########.fr       */
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

/* autoheaders */
int					ft_putnbr_pointer(unsigned long nbr);
int					ft_putnbr_hexa(unsigned int nbr, char *base);
int					ft_putnbr_unsigned(unsigned int n);
int					ft_putnbr(long n);
int					ft_putstr(char *s);
int					ft_printf(const char *format, ...);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t size);
void				create_stack(t_stack **sa, char **args, int *result);
t_stack				*ft_parse_args(int argc, char **argv, int *algorithm);
int					ft_atoi(const char *n_str, long *n);
t_stack				*ft_stacknew(int value);
t_stack				*ft_stacklast(t_stack *lst);
void				ft_stackadd_back(t_stack **lst, t_stack *new_node);
void				free_args(char **args);
void				free_stack(t_stack **stack);
void				print_error_end_free_exit(t_stack **sa, char **args);
int					is_duplicate(t_stack *sa, int n);
int					is_flags(char *args);
int					ft_strcmp(char *s1, char *s2);
void				swap_move(t_stack **sa);
void				swap(t_stack *top);
#endif
