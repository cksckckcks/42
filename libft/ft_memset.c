/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:51:31 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/03 18:01:51 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*temp;

	temp = (unsigned char *) s;
	index = 0;
	while (index < n)
	{
		temp[index] = (unsigned char) c;
		index++;
	}
	return (temp);
}
