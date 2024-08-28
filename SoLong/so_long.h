/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:57:24 by chjeong           #+#    #+#             */
/*   Updated: 2024/08/05 19:57:26 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./libft/get_next_line.h"

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

typedef struct	s_image_data
{
	t_image	*img_0;
	t_image	*img_1;
	t_image	*img_C;
	t_image	*img_E;
	t_image	*img_P;
}				 t_image_data;

typedef struct  s_vars
{
    void        	*mlx;
    void        	*win;
	char			**map;
	int				x;
	int				y;
	int				row;
	int				col;
	int				c_cnt;
	int				move_cnt;
	t_image_data	*image;
}               t_vars;

typedef struct s_map_data
{
	char	**map;
	int		row;
	int		col;
}				t_map_data;

int		line_check(char *str);
int		get_fd(char *filename);
int		press_mouse(t_vars **vars);
int		input_file_check(char *name);
int		line_length_check(char *str);
int		map_essential_check(char **map);
int		press_key(int keycode, t_vars **vars);
int		map_check(int fd, int *row, int *col);
int		path_check(char **map, int row, int col);
int		side_map_check(char **map, int row, int col);
int		visited_check(char **map, int **visited, int row, int col);
void	map_free(char **map);
void	print_error(char *str);
void	print_cnt(t_vars **vars);
void	finish_solong(t_vars **vars);
void	get_row_col_p(t_vars **vars);
void	get_image_pointer(t_vars **vars);
void	get_image_pointer2(t_vars **vars);
void	visited_free(int **visited, int row);
void	put_images(t_vars **vars, char **map);
void	mem_set_zero(int **arr, int row, int col);
void	change_map(t_vars **vars, int dx, int dy);
void	get_start_point(char **map, int *x, int *y);
void	dfs(char **map, int **visited, int x, int y);
char	**map_path_check(char *filename);
char	**creat_map(int fd, int row, int col);

#endif