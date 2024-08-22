/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:44:40 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/10 19:06:40 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	slength;

	if (s == NULL)
		return (NULL);
	slength = ft_strlen(s);
	if (slength <= start)
	{
		tmp = (char *)malloc(sizeof(char) * 1);
		tmp[0] = '\0';
		return (tmp);
	}
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	ft_strlcpy(tmp, s + start, len + 1);
	return (tmp);
}
