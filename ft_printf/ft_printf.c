/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:01:05 by chjeong           #+#    #+#             */
/*   Updated: 2024/05/12 14:12:29 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printf_check(char check, va_list *ptr)
{
	size_t	cnt;

	cnt = 0;
	if (check == 'c')
		cnt = print_char(va_arg((*ptr), int));
	else if (check == 's')
		cnt = print_string(va_arg((*ptr), char *));
	else if (check == 'p')
		cnt = print_x(va_arg((*ptr), unsigned long long), 0);
	else if (check == 'd' || check == 'i')
		cnt = print_int(va_arg((*ptr), int));
	else if (check == 'u')
		cnt = print_uint(va_arg((*ptr), unsigned int));
	else if (check == 'x' || check == 'X')
		cnt = print_pointer(va_arg((*ptr), unsigned int), check == 'X');
	else if (check == '%')
		cnt = print_char('%');
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	size_t	cnt;

	cnt = 0;
	if (format == NULL)
		return (-1);
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%')
			cnt += printf_check(*(++format), &ptr);
		else
			cnt += print_char(*format);
		format++;
	}
	va_end(ptr);
	return (cnt);
}
