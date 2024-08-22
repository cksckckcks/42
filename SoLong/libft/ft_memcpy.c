/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:10:03 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/09 18:55:39 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*temp;
	const unsigned char	*s;
	size_t				index;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp = (unsigned char *) dest;
	s = (const unsigned char *)src;
	index = 0;
	while (index < n)
	{
		temp[index] = s[index];
		index++;
	}
	return (dest);
}
