/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:22:18 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/05 14:27:45 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	slength;
	char	*tmp;

	slength = ft_strlen(s);
	tmp = (char *)malloc(sizeof(char) * (slength + 1));
	if (tmp == NULL)
		return (NULL);
	ft_memcpy(tmp, s, slength);
	tmp[slength] = '\0';
	return (tmp);
}
