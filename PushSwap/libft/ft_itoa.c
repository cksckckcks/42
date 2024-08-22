/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:40:29 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/12 15:59:55 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_digit(int n)
{
	long long	div;
	size_t		count;

	count = 0;
	div = 1;
	while (n / div != 0)
	{
		div *= 10;
		count++;
	}
	return (count);
}

static char	*set_itoa(int n, int length, int sign)
{
	char	*tmp;
	int		div;

	if (n == 0)
	{
		tmp = (char *)malloc(sizeof(char) * 2);
		if (tmp == NULL)
			return (NULL);
		tmp[0] = '0';
		tmp[1] = '\0';
		return (tmp);
	}
	div = 10;
	tmp = (char *)malloc(sizeof(char) * (length + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[length] = '\0';
	while (length--)
	{
		tmp[length] = n % div * sign + '0';
		n /= div;
	}
	if (sign == -1)
		tmp[0] = '-';
	return (tmp);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	int		sign;
	size_t	length;

	sign = 1;
	length = 0;
	if (n < 0)
	{
		sign *= -1;
		length++;
	}
	length += check_digit(n);
	tmp = set_itoa(n, length, sign);
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}
