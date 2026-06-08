/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:19:21 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/07 20:05:48 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *n_str, long *n)
{
	int		i;
	long	sinal;
	long	dest;

	i = 0;
	sinal = 1;
	dest = 0;
	if (n_str[i] == '+' || n_str[i] == '-')
		if (n_str[i++] == '-')
			sinal *= -1;
	if (!n_str[i])
		return (1);
	while (n_str[i] && (n_str[i] >= '0' && n_str[i] <= '9'))
		dest = (dest * 10) + (n_str[i++] - '0');
	dest = (dest * sinal);
	if (n_str[i])
		return (1);
	if (dest > (long)INT_MAX || dest < (long)INT_MIN)
		return (1);
	*n = dest;
	return (0);
}

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
