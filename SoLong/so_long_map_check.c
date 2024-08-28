/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:57:02 by chjeong           #+#    #+#             */
/*   Updated: 2024/08/05 19:57:03 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(int fd, int *row, int *col)
{
	char	*str;

	str = get_next_line(fd);
	if (!str)
		return (0);
	(*row) = 0;
	(*col) = line_length_check(str);
	while (str != NULL)
	{
		if ((*col) != line_length_check(str) || !line_check(str))
		{
			close(fd);
			free(str);
			return (0);
		}
		free(str);
		str = get_next_line(fd);
		(*row)++;
	}
	close(fd);
	return (1);
}

int	map_essential_check(char **map)
{
	int	i;
	int	j;
	int	check_e;
	int	check_c;
	int	check_p;

	check_e = 0;
	check_c = 0;
	check_p = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				check_e++;
			else if (map[i][j] == 'C')
				check_c++;
			else if (map[i][j] == 'P')
				check_p++;
		}
	}
	return (check_e == 1 && check_c && check_p == 1);
}

int	side_map_check(char **map, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		if (map[i][0] != '1' || map[i][col - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < col)
	{
		if (map[0][j] != '1' || map[row - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	visited_check(char **map, int **visited, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				if (visited[i][j] != 1)
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	path_check(char **map, int row, int col)
{
	int	x;
	int	y;
	int	i;
	int	ret;
	int	**visited;

	visited = (int **)malloc(sizeof(int *) * row);
	if (!visited)
		return (0);
	i = 0;
	while (i < row)
	{
		visited[i] = (int *)malloc(sizeof(int) * col);
		if (!visited[i])
			visited_free(visited, i);
		i++;
	}
	mem_set_zero(visited, row, col);
	get_start_point(map, &x, &y);
	dfs(map, visited, x, y);
	ret = visited_check(map, visited, row, col);
	visited_free(visited, row);
	return (ret);
}
