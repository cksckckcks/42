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

void	finish_solong(t_vars **vars)
{
	mlx_destroy_image((*vars)->mlx, (*vars)->image->img_0->ptr);
	mlx_destroy_image((*vars)->mlx, (*vars)->image->img_1->ptr);
	mlx_destroy_image((*vars)->mlx, (*vars)->image->img_C->ptr);
	mlx_destroy_image((*vars)->mlx, (*vars)->image->img_E->ptr);
	mlx_destroy_image((*vars)->mlx, (*vars)->image->img_P->ptr);
	free((*vars)->image->img_0);
	free((*vars)->image->img_1);
	free((*vars)->image->img_C);
	free((*vars)->image->img_E);
	free((*vars)->image->img_P);
	free((*vars)->image);
	map_free((*vars)->map);
	mlx_destroy_display((*vars)->mlx);
	mlx_destroy_window((*vars)->mlx, (*vars)->win);
	free((*vars)->mlx);
	free((*vars));
	exit(0);
}

void	change_map(t_vars **vars, int dx, int dy)
{
	int	x;
	int	y;

	x = ((*vars)->x) + dx;
	y = ((*vars)->y) + dy;
	if ((*vars)->map[x][y] == '1')
		return ;
	if ((*vars)->map[x][y] == 'E' && (*vars)->c_cnt > 0)
		return ;
	if ((*vars)->map[x][y] == 'E')
		finish_solong(vars);
	if ((*vars)->map[x][y] == 'C')
	{
		(*vars)->map[x][y] = '0';
		((*vars)->c_cnt)--;
	}
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, \
	(*vars)->image->img_0->ptr, (*vars)->y * 50, (*vars)->x * 50);
	(*vars)->x = x;
	(*vars)->y = y;
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, \
	(*vars)->image->img_P->ptr, (*vars)->y * 50, (*vars)->x * 50);
	print_cnt(vars);
}

void	get_image_pointer(t_vars **vars)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	img->ptr = mlx_xpm_file_to_image((*vars)->mlx, "./image/item.xpm", \
	&img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bits_per_pixel, \
	&img->size_line, &img->endian);
	(*vars)->image->img_C = img;
	img = (t_image *)malloc(sizeof(t_image));
	img->ptr = mlx_xpm_file_to_image((*vars)->mlx, "./image/exit.xpm", \
	&img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bits_per_pixel, \
	&img->size_line, &img->endian);
	(*vars)->image->img_E = img;
	img = (t_image *)malloc(sizeof(t_image));
	img->ptr = mlx_xpm_file_to_image((*vars)->mlx, "./image/player.xpm", \
	&img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bits_per_pixel, \
	&img->size_line, &img->endian);
	(*vars)->image->img_P = img;
	get_image_pointer2(vars);
}

void	get_image_pointer2(t_vars **vars)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	img->ptr = mlx_xpm_file_to_image((*vars)->mlx, "./image/floor.xpm", \
	&img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bits_per_pixel, \
	&img->size_line, &img->endian);
	(*vars)->image->img_0 = img;
	img = (t_image *)malloc(sizeof(t_image));
	img->ptr = mlx_xpm_file_to_image((*vars)->mlx, "./image/wall.xpm", \
	&img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bits_per_pixel, \
	&img->size_line, &img->endian);
	(*vars)->image->img_1 = img;
}

void	put_images(t_vars **vars, char **map)
{
	int		x;
	int		y;
	void	*ptr;

	get_image_pointer(vars);
	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == '0')
				ptr = (*vars)->image->img_0->ptr;
			else if (map[x][y] == '1')
				ptr = (*vars)->image->img_1->ptr;
			else if (map[x][y] == 'C')
				ptr = (*vars)->image->img_C->ptr;
			else if (map[x][y] == 'E')
				ptr = (*vars)->image->img_E->ptr;
			else if (map[x][y] == 'P')
				ptr = (*vars)->image->img_P->ptr;
			mlx_put_image_to_window((*vars)->mlx, (*vars)->win, \
			ptr, y * 50, x * 50);
		}
	}
}
