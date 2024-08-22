/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:39:15 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/12 21:15:54 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	if (dest == NULL && size == 0)
		return (0);
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	i = dest_length;
	j = 0;
	if (dest_length >= size)
		return (size + src_length);
	while (i + 1 < size && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (src_length + dest_length);
}
