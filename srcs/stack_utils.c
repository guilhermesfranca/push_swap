/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:57:04 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/07 23:02:04 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_circular_newnode(int value)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->index = -1;
	newnode->next = newnode;
	newnode->prev = newnode;
	return (newnode);
}

void	ft_circular_add_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*last;

	if (!lst || !new_node)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	last = (*lst)->prev;
	last->next = new_node;
	new_node->prev = last;
	new_node->next = *lst;
	(*lst)->prev = new_node;
}

int	ft_stacksize(t_stack *stack)
{
	t_stack	*current;
	int		size;

	if (!stack)
		return (0);
	size = 0;
	current = stack;
	while (1)
	{
		size++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (size);
}
