/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 21:50:06 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/13 21:56:23 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int	main(void)
{
	t_list	*lst;
	t_list	*n0 = malloc(sizeof(t_list));
	t_list	*n1 = malloc(sizeof(t_list));
	t_list	*n2 = malloc(sizeof(t_list));
	t_list	*new = malloc(sizeof(t_list));

	n0->content = "1";
	n0->next = n1;

	n1->content = "2";
	n1->next = n2;

	n2->content = "3";
	n2->next = NULL;

	new->content = "0";
	new->next = NULL;

	lst = n0;
	printf("--- ANTES DO ADD_FRONT ---\nprimeiro no: %s\n", (char *)lst->content);
	printf("proximo no: %s\n", (char *)lst->next->content);

	ft_lstadd_front(&lst, new);
	printf("--- DEPOIS DO ADD_FRONT ---\nnovo primero no: %s\n", (char *)lst->content);
	printf("primeiro no(agora segundo): %s\n", (char *)lst->next->content);

	free(n0);
	free(n1);
	free(n2);
	free(new);
	return (0);
}