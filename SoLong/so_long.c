/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:57:02 by chjeong           #+#    #+#             */
/*   Updated: 2024/08/05 19:57:03 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


typedef struct s_image
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;

	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_image;

typedef struct  s_vars
{
    void        *mlx;
    void        *win;
	char		**map;
	int			x;
	int			y;
	int			row;
	int			col;
}               t_vars;

typedef struct	s_image_data
{
	t_image	*img_0;
	t_image	*img_1;
	t_image	*img_C;
	t_image	*img_E;
	t_image	*img_P;
}				 t_image_data;

typedef struct s_map_data
{
	char	**map;
	int		row;
	int		col;
}				t_map_data;

void	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

int	input_file_check(char *name)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (name[i + 1] == 'b' && name[i + 2] == 'e'\
		&& name[i + 3] == 'r' && name[i + 4] == '\0')
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

int	get_fd(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (fd);
}

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
			return (0);
		}
		free(str);
		str = get_next_line(fd);
		(*row)++;
	}
	close(fd);
	return (1);
}

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	visited_free(int **visited, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	map_essential_check(char **map)
{
	int	i;
	int	j;
	int	check_E;
	int	check_C;
	int	check_P;

	check_E = 0;
	check_C = 0;
	check_P = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				check_E++;
			else if (map[i][j] == 'C')
				check_C++;
			else if (map[i][j] == 'P')
				check_P++;
		}
	}
	return (check_E == 1 && check_C && check_P == 1);
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

char	**creat_map(int fd, int row, int col)
{
	int		i;
	char	*tmp;
	char	**ret;
	
	ret = (char**)malloc(sizeof(char*) * (row + 1));
	if (!ret)
		return (0);
	ret[row] = NULL;
	i = 0;
	while (i < row)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			map_free(ret);
			return (0);
		}
		ret[i] = tmp;
		ret[i][col] = '\0';
		i++;
	}
	if (map_essential_check(ret) && side_map_check(ret, row, col))
		return (ret);
	map_free(ret);
	return (NULL);
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

void	mem_set_zero(int **arr, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	dfs(char **map, int** visited, int x, int y)
{
	if (visited[x][y] == 1 || map[x][y] == '1')
		return ;
	visited[x][y] = 1;
	dfs(map, visited, x, y + 1);
	dfs(map, visited, x, y - 1);
	dfs(map, visited, x + 1, y);
	dfs(map, visited, x - 1, y);
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
	int ret;
	int	**visited;

	visited = (int**)malloc(sizeof(int*) * row);
	if (!visited)
		return 0;
	i = 0;
	while (i < row)
	{
		visited[i] = (int*)malloc(sizeof(int) * col);
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

char	**map_path_check(char *filename)
{
	int	fd;
	int	row;
	int	col;
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

// w : 119
// a : 97
// s : 115
// d : 100
int	press_key(int keycode, t_vars **vars)
{
	if (keycode == 65307) // esc : 65307
	{
		write(1, "Press Esc\n", 10);
    	mlx_destroy_window((*vars)->mlx, (*vars)->win);
		exit(0);
	}
	return (0);
}

void	get_image_pointer(t_vars *vars, t_image_data **images)
{
	t_image	*img;
	
	img = (t_image *)malloc(sizeof(t_image));
	img->ptr = mlx_xpm_file_to_image(vars->mlx, "./image/floor.xpm", &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bits_per_pixel, &img->size_line, &img->endian);
	(*images)->img_0 = img;
	img = (t_image *)malloc(sizeof(t_image));
	img->ptr = mlx_xpm_file_to_image(vars->mlx, "./image/wall.xpm", &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bits_per_pixel, &img->size_line, &img->endian);
	(*images)->img_1 = img;
	img = (t_image *)malloc(sizeof(t_image));
	img->ptr = mlx_xpm_file_to_image(vars->mlx, "./image/item.xpm", &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bits_per_pixel, &img->size_line, &img->endian);
	(*images)->img_C = img;
	img = (t_image *)malloc(sizeof(t_image));
	img->ptr = mlx_xpm_file_to_image(vars->mlx, "./image/exit.xpm", &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bits_per_pixel, &img->size_line, &img->endian);
	(*images)->img_E = img;
	img = (t_image *)malloc(sizeof(t_image));
	img->ptr = mlx_xpm_file_to_image(vars->mlx, "./image/player.xpm", &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bits_per_pixel, &img->size_line, &img->endian);
	(*images)->img_P = img;
}

void	put_images(t_vars *vars, char **map, t_image_data **images)
{
	int	x;
	int	y;

	get_image_pointer(vars, images);
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, (*images)->img_0->ptr, y * 50, x * 50);
			else if (map[x][y] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, (*images)->img_1->ptr, y * 50, x * 50);
			else if (map[x][y] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, (*images)->img_C->ptr, y * 50, x * 50);
			else if (map[x][y] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, (*images)->img_E->ptr, y * 50, x * 50);
			else if (map[x][y] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, (*images)->img_P->ptr, y * 50, x * 50);
			y++;
		}
		x++;	
	}
	mlx_destroy_image(vars->mlx, (*images)->img_0->ptr); // 해제
	mlx_destroy_image(vars->mlx, (*images)->img_1->ptr);
	mlx_destroy_image(vars->mlx, (*images)->img_C->ptr);
	mlx_destroy_image(vars->mlx, (*images)->img_E->ptr);
	mlx_destroy_image(vars->mlx, (*images)->img_P->ptr);
}

int	main(int argc, char **argv)
{
	t_vars			*vars;
	t_image			*img;
	t_image_data	*imgs;

	img = (t_image *)malloc(sizeof(t_image));
	imgs = (t_image_data *)malloc(sizeof(t_image_data));
	vars = (t_vars *)malloc(sizeof(t_vars));

	if (argc != 2)
		print_error("./so_long filename.ber\n");

	vars->map = map_path_check(argv[1]);

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 500, 500, "test window!!");

	put_images(vars, vars->map, &imgs);
	mlx_hook(vars->win, 2, 1L<<0, press_key, &vars);
	mlx_loop(vars->mlx);

	map_free(vars->map);
	free(img);
	free(imgs);
	free(vars);
	exit(0);
}



/*
int	main(int argc, char **argv)
{
	char	**map;
	t_img	img;
	t_vars	vars;
	char	*path = "./image/item.xpm";

	if (argc != 2)
		print_error("./so_long filename.ber\n");
	map = map_path_check(argv[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "test window!!");
	
	//mlx_clear_window(vars.mlx, vars.win);

	img.ptr = mlx_xpm_file_to_image(vars.mlx, path, &img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img.ptr, 0, 0);


	

	mlx_hook(vars.win, 2, 1L<<0, press_key, &vars);
	//mlx_key_hook(vars.win, my_close, &vars);
	mlx_loop(vars.mlx);

	map_free(map);
}
*/
