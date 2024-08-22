/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:37:10 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/03 13:38:12 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;
	size_t			i;

	tmp = (unsigned char *) buf1;
	tmp2 = (unsigned char *) buf2;
	i = 0;
	while (i < count)
	{
		if (tmp[i] != tmp2[i])
			return (tmp[i] - tmp2[i]);
		i++;
	}
	return (0);
}
