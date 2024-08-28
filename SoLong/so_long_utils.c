/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:57:02 by chjeong           #+#    #+#             */
/*   Updated: 2024/08/05 19:57:03 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

char	**creat_map(int fd, int row, int col)
{
	int		i;
	char	*tmp;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (row + 1));
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

void	print_cnt(t_vars **vars)
{
	char	*cnt;

	cnt = ft_itoa((*vars)->move_cnt);
	if (cnt == NULL)
		print_error("Error\n");
	ft_putstr_fd(cnt, 1);
	write(1, "\n", 1);
	((*vars)->move_cnt)++;
	free(cnt);
}
