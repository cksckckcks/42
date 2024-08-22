/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:40:24 by chjeong           #+#    #+#             */
/*   Updated: 2024/05/18 17:17:45 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join(char **s, char **src, int slength, int srclength)
{
	char	*ret;
	int		i;

	ret = (char *)malloc (sizeof(char) * (slength + srclength + 1));
	if (ret == NULL)
		return (NULL);
	i = -1;
	while (++i < slength + srclength)
	{
		if (i < slength)
			ret[i] = (*s)[i];
		else
			ret[i] = (*src)[i - slength];
	}
	ret[i] = '\0';
	free((*s));
	free((*src));
	(*s) = NULL;
	(*src) = NULL;
	if (i == 0)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

char	*get_line_save_buf(char **save, int loc)
{
	char	*ret;

	ret = get_line_buf((*save), loc);
	(*save) = save_string(&(*save), loc + 1);
	return (ret);
}

char	*get_line_read_buf(char **read, char **save, char **ret, int loc)
{
	(*ret) = get_line_buf((*read), loc);
	(*read) = save_string(&(*read), loc + 1);
	(*ret) = join(&(*save), &(*ret), ft_strlen(*save), ft_strlen(*ret));
	(*save) = (*read);
	(*read) = NULL;
	return ((*ret));
}

void	*read_free(char **buf, char **save)
{
	if ((*save) != NULL)
	{
		free((*save));
		save = NULL;
	}
	free((*buf));
	(*buf) = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*tmp;
	char		*ret;
	int			read_check;
	int			loc;

	while (1)
	{
		loc = str_in_newline(save);
		if (loc >= 0)
			return (get_line_save_buf(&save, loc));
		tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (tmp == NULL)
			return (NULL);
		read_check = read(fd, tmp, BUFFER_SIZE);
		if (read_check == -1 || (read_check == 0 && save == NULL))
			return (read_free(&tmp, &save));
		tmp[read_check] = '\0';
		loc = str_in_newline(tmp);
		if (loc >= 0)
			return (get_line_read_buf(&tmp, &save, &ret, loc));
		if (read_check < BUFFER_SIZE)
			return (join(&save, &tmp, ft_strlen(save), ft_strlen(tmp)));
		save = join(&save, &tmp, ft_strlen(save), ft_strlen(tmp));
	}
}
