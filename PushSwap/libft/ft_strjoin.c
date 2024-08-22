/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:28:58 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/10 17:27:10 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1length;
	size_t	s2length;
	size_t	i;
	char	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1length = ft_strlen(s1);
	s2length = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (s1length + s2length + 1));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (i < s1length + s2length)
	{
		if (i >= s1length)
			tmp[i] = s2[i - s1length];
		else
			tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
