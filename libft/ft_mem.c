/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:18:02 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/31 18:55:26 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *)s;
	ch = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*c_src;
	unsigned char		*c_dest;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	c_src = (const unsigned char *)src;
	c_dest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*c_src;
	unsigned char		*c_dest;

	if (!dest && !src)
		return (NULL);
	c_src = (const unsigned char *)src;
	c_dest = (unsigned char *)dest;
	if (c_dest < c_src)
	{
		while (n--)
			*c_dest++ = *c_src++;
	}
	else if (c_dest > c_src)
	{
		while (n--)
			c_dest[n] = c_src[n];
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		*str = c;
		str++;
		n--;
	}
	return ((void *)s);
}
