/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:15:03 by chjeong           #+#    #+#             */
/*   Updated: 2024/05/12 14:14:50 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *s)
{
	size_t	cnt;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	cnt = 0;
	while (*s)
	{
		print_char(*s);
		cnt++;
		s++;
	}
	return (cnt);
}

int	print_int(int n)
{
	size_t	cnt;
	char	c;

	cnt = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		cnt++;
	}
	if (n / 10 > 0)
		cnt += print_int(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	cnt++;
	return (cnt);
}

int	print_x(unsigned long long addr, int sign)
{
	size_t	cnt;

	if (addr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	cnt = write(1, "0x", 2);
	cnt += print_pointer(addr, sign);
	return (cnt);
}

int	print_pointer(unsigned long long addr, int sign)
{
	char	c;
	int		n;
	size_t	cnt;

	cnt = 0;
	n = addr % 16;
	if (n < 10)
		c = '0' + n;
	else if (sign == 0)
		c = 'a' + (n - 10);
	else
		c = 'A' + (n - 10);
	if (addr / 16 != 0)
		cnt += print_pointer(addr / 16, sign);
	write(1, &c, 1);
	cnt++;
	return (cnt);
}

int	print_uint(unsigned int n)
{
	size_t	cnt;
	char	c;

	cnt = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n / 10 > 0)
		cnt += print_uint(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	cnt++;
	return (cnt);
}
