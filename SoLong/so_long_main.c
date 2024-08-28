/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:57:02 by chjeong           #+#    #+#             */
/*   Updated: 2024/08/05 19:57:03 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int keycode, t_vars **vars)
{
	if (keycode == 65307)
	{
		write(1, "Press Esc\n", 10);
		finish_solong(vars);
		exit(0);
	}
	else if (keycode == 97)
		change_map(vars, 0, -1);
	else if (keycode == 100)
		change_map(vars, 0, 1);
	else if (keycode == 115)
		change_map(vars, 1, 0);
	else if (keycode == 119)
		change_map(vars, -1, 0);
	return (0);
}

int	press_mouse(t_vars **vars)
{
	finish_solong(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars			*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	vars->image = (t_image_data *)malloc(sizeof(t_image_data));
	vars->move_cnt = 1;
	if (argc != 2)
		exit(1);
	vars->map = map_path_check(argv[1]);
	get_row_col_p(&vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->col * 50, \
	vars->row * 50, "solong!!");
	put_images(&vars, vars->map);
	mlx_hook(vars->win, 2, 1L << 0, press_key, &vars);
	mlx_hook(vars->win, 17, 1L << 2, press_mouse, &vars);
	mlx_loop(vars->mlx);
	return (0);
}
