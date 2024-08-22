/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:49:29 by chjeong           #+#    #+#             */
/*   Updated: 2024/05/18 16:54:27 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		ft_strlen2(char *s);
int		str_in_newline(char *s);
char	*get_line_buf(char *s, int size);
char	*save_string(char **s, int loc);
char	*join(char **s, char **src, int slength, int srclength);
char	*get_line_save_buf(char **save_buf, int loc);
char	*get_line_read_buf(char **read, char **save, char **ret, int loc);
void	*read_free(char **buf, char **save);
char	*get_next_line(int fd);

#endif
