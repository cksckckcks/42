/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:03:46 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/03 17:48:12 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			index;
	unsigned char	*temp;

	temp = (unsigned char *) s;
	index = 0;
	while (index < n)
	{
		temp[index] = 0;
		index++;
	}
}
