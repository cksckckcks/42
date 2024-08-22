/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:48:45 by chjeong           #+#    #+#             */
/*   Updated: 2024/05/18 17:17:54 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	str_in_newline(char *s)
{
	int	i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_line_buf(char *s, int size)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (size + 2));
	if (ret == NULL)
		return (NULL);
	while (i <= size)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*save_string(char **s, int loc)
{
	int		i;
	int		size;
	char	*ret;

	if ((*s) == NULL)
		return (NULL);
	size = ft_strlen(&(*s)[loc]);
	if (size < 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	i = loc;
	while (i - loc < size)
	{
		ret[i - loc] = (*s)[i];
		i++;
	}
	ret[i - loc] = '\0';
	free((*s));
	(*s) = NULL;
	return (ret);
}
