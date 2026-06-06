/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranca <gfranca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 21:50:31 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/06 17:59:15 by gfranca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_putnbr_p(unsigned long nbr, int fd)
{
	int		size;
	char	*base;

	base = "0123456789abcdef";
	size = 0;
	if (nbr >= 16)
		size = size + ft_putnbr_p(nbr / 16, fd);
	write(fd, &base[nbr % 16], 1);
	size++;
	return (size);
}

int	ft_putnbr_h(unsigned int nbr, char *base, int fd)
{
	int		size;

	size = 0;
	if (nbr >= 16)
		size = size + ft_putnbr_h(nbr / 16, base, fd);
	write(fd, &base[nbr % 16], 1);
	size++;
	return (size);
}

int	ft_putnbr_u(unsigned int n, int fd)
{
	char	nbr;
	int		size;

	size = 0;
	if (n >= 10)
		size = size + ft_putnbr_u(n / 10, fd);
	nbr = (n % 10) + 48;
	write(fd, &nbr, 1);
	size++;
	return (size);
}

int	ft_putnbr(long n, int fd)
{
	char	nbr;
	int		size;

	size = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		size++;
	}
	if (n >= 10)
		size = size + ft_putnbr(n / 10, fd);
	nbr = (n % 10) + 48;
	write(fd, &nbr, 1);
	size++;
	return (size);
}

int	ft_putstr(char *s, int fd)
{
	int	i;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
