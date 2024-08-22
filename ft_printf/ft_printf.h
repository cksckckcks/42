/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:37:37 by chjeong           #+#    #+#             */
/*   Updated: 2024/05/12 14:15:04 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		print_char(char c);
int		printf_check(char check, va_list *ptr);
int		ft_printf(const char *format, ...);
int		print_string(char *s);
int		print_int(int n);
int		print_x(unsigned long long addr, int sign);
int		print_pointer(unsigned long long addr, int sign);
int		print_uint(unsigned int n);

#endif
