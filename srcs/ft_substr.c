/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:36:42 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/05 11:31:17 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t size)
{
	char	*new;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (start >= len)
	{
		new = malloc(1);
		return (new = NULL, new);
	}
	if (size > len - start)
		size = len - start;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char	*str;
// 	int		start;
// 	int		len;
//
// 	str = "Geeks";
// 	start = 1;
// 	len = 10;
// 	printf("%s\n", ft_substr(str, start, len));
// 	return (0);
// }