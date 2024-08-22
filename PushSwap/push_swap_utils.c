/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:52:56 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:23:47 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if ((str[0] == '-' && str[1] == '0') || (str[0] == '0' && str[1]))
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') == 0)
			return (0);
		i++;
	}
	if (i == 1 && str[0] == '-')
		return (0);
	return (1);
}

int	check_integer(long long n)
{
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}

int	char_to_integer(char *str, int *n)
{
	long long	ret;
	int			sign;
	int			i;

	if (ft_strlen(str) == 0)
		return (0);
	i = 0;
	sign = 1;
	ret = 0;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i])
	{
		ret = ret * 10 + str[i] - '0';
		if (!check_integer(ret * sign))
			return (0);
		i++;
	}
	*n = sign * ret;
	return (1);
}

int	input_dup_check(int *arr, int idx, int n)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (arr[i] == n)
			return (0);
		i++;
	}
	return (1);
}

int	check_input_sort(int *input, int size)
{
	int	i;

	i = 1;
	if (size == 2)
	{
		if (input[0] < input[1])
			return (1);
		return (0);
	}
	while (i + 1 < size)
	{
		if ((input[i - 1] < input[i] && input[i] < input[i + 1]) == 0)
			return (0);
		i++;
	}
	return (1);
}
