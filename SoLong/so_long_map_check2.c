/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:57:02 by chjeong           #+#    #+#             */
/*   Updated: 2024/08/05 19:57:03 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(char **map, int **visited, int x, int y)
{
	if (visited[x][y] == 1 || map[x][y] == '1')
		return ;
	visited[x][y] = 1;
	dfs(map, visited, x, y + 1);
	dfs(map, visited, x, y - 1);
	dfs(map, visited, x + 1, y);
	dfs(map, visited, x - 1, y);
}

char	**map_path_check(char *filename)
{
	int		fd;
	int		row;
	int		col;
	char	**map;

	if (input_file_check(filename) == 0)
		print_error("Error\n");
	fd = get_fd(filename);
	if (!map_check(fd, &row, &col))
		print_error("Map Error\n");
	fd = get_fd(filename);
	map = creat_map(fd, row, col);
	if (!map)
		print_error("Map Error\n");
	if (!path_check(map, row, col))
		print_error("Path Error\n");
	return (map);
}

int	input_file_check(char *name)
{
	int	i;

	i = 0;
	i = ft_strlen(name);
	if (name[i - 4] == '.' && name[i - 3] == 'b' && name[i - 2] == 'e'\
		&& name[i - 1] == 'r')
		return (1);
	return (0);
}

int	line_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C'\
			&& str[i] != 'E' && str[i] != 'P')
			return (0);
		i++;
	}
	return (1);
}

int	line_length_check(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
