/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 21:50:31 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/05 11:31:07 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_putnbr_pointer(unsigned long nbr)
{
	int		size;
	char	*base;

	base = "0123456789abcdef";
	size = 0;
	if (nbr >= 16)
		size = size + ft_putnbr_pointer(nbr / 16);
	write(1, &base[nbr % 16], 1);
	size++;
	return (size);
}

int	ft_putnbr_hexa(unsigned int nbr, char *base)
{
	int		size;

	size = 0;
	if (nbr >= 16)
		size = size + ft_putnbr_hexa(nbr / 16, base);
	write(1, &base[nbr % 16], 1);
	size++;
	return (size);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	nbr;
	int		size;

	size = 0;
	if (n >= 10)
		size = size + ft_putnbr_unsigned(n / 10);
	nbr = (n % 10) + 48;
	write(1, &nbr, 1);
	size++;
	return (size);
}

int	ft_putnbr(long n)
{
	char	nbr;
	int		size;

	size = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		size++;
	}
	if (n >= 10)
		size = size + ft_putnbr(n / 10);
	nbr = (n % 10) + 48;
	write(1, &nbr, 1);
	size++;
	return (size);
}


int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
