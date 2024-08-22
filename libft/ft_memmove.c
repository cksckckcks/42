/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:39:46 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/09 16:37:52 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp;
	const unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (temp <= s)
		while (n--)
			*temp++ = *s++;
	else
	{
		temp += n;
		s += n;
		while (n--)
			*(--temp) = *(--s);
	}
	return (dest);
}
