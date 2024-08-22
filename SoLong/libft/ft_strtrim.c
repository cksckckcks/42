/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:43:03 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/12 16:00:36 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*tmp;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	while (isset(s1[start], set) && s1[start])
		start++;
	end = ft_strlen(s1);
	while (isset(s1[end - 1], set) && start < end)
		end--;
	tmp = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, &s1[start], (end - start + 1));
	return (tmp);
}
