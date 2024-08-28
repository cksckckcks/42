/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_get_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:57:02 by chjeong           #+#    #+#             */
/*   Updated: 2024/08/05 19:57:03 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_row_col_p(t_vars **vars)
{
	int	i;
	int	j;

	i = 0;
	(*vars)->c_cnt = 0;
	while ((*vars)->map[i])
	{
		j = 0;
		while ((*vars)->map[i][j])
		{
			if ((*vars)->map[i][j] == 'P')
			{
				(*vars)->x = i;
				(*vars)->y = j;
			}
			if ((*vars)->map[i][j] == 'C')
				((*vars)->c_cnt)++;
			j++;
		}
		i++;
	}
	(*vars)->row = i;
	(*vars)->col = j;
}

void	get_start_point(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	get_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (fd);
}
