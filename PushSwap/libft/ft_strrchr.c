/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:42:12 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/05 15:10:00 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		result;

	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	result = -1;
	while (s[i])
	{
		if (s[i] == c)
			result = i;
		i++;
	}
	if (result == -1)
		return (NULL);
	else
		return ((char *) &s[result]);
}
