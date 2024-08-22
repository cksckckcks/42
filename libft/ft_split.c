/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:08:35 by chjeong           #+#    #+#             */
/*   Updated: 2024/03/12 15:59:21 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (*s == '\0')
		return (0);
	count = 0;
	if (s[0] != c)
		count++;
	i = 0;
	while (s[i++])
		if (s[i - 1] == c && s[i] != c && s[i])
			count++;
	return (count);
}

static size_t	word_length(char const **s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (**s == c)
		(*s)++;
	while ((*s)[i] != c && (*s)[i++])
		count++;
	return (count);
}

static char	**memfree(char **mem, int n)
{
	while (n--)
		free(mem[n]);
	free(mem);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	wordcnt;
	size_t	i;
	size_t	wordlen;
	char	**tmp;

	if (s == NULL)
		return (NULL);
	wordcnt = word_count(s, c);
	tmp = (char **)malloc(sizeof(char *) * (wordcnt + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (wordcnt--)
	{
		wordlen = word_length(&s, c);
		tmp[i] = (char *)malloc(sizeof(char) * (wordlen + 1));
		if (!tmp[i])
			return (memfree(tmp, i));
		ft_strlcpy(tmp[i++], s, wordlen + 1);
		s += wordlen;
	}
	tmp[i] = NULL;
	return (tmp);
}
