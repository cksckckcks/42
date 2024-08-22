/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:49:37 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:12:52 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_arr(int **arr)
{
	free(*arr);
	return (NULL);
}

int	*put_input(t_stack **stc, char **input, int size, int sign)
{
	int	i;
	int	n;
	int	*arr;

	arr = array_allocate(size);
	if (!arr)
		return (NULL);
	i = 0 + sign;
	while (i < size)
	{
		if (check_digit(input[i]))
		{
			if (!(char_to_integer(input[i], &n)))
				return (free_arr(&arr));
			stack_push_back(stc, n, -1);
			arr[i - sign] = n;
			if (!(input_dup_check(arr, i - sign, arr[i - sign])))
				return (free_arr(&arr));
			i++;
		}
		else
			return (free_arr(&arr));
	}
	return (arr);
}

int	check_input_size(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

void	free_input(char	**input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}

int	main(int argc, char **argv)
{
	int		tmp_size;
	int		*tmp_arr;
	char	**tmp_input;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		print_error("./push_swap [int values]\n");
	stack_allocate(&a, &b, 'a', 'b');
	tmp_size = argc - 1;
	if (argc == 2)
	{
		tmp_input = ft_split(argv[1], ' ');
		tmp_size = check_input_size(tmp_input);
		tmp_arr = put_input(&a, tmp_input, tmp_size, 0);
		free_input(tmp_input);
	}
	else
		tmp_arr = put_input(&a, argv, argc, 1);
	if (tmp_arr == NULL || tmp_size == 0)
		free_and_error(&a, &b);
	if (check_input_sort(tmp_arr, tmp_size))
		free_stacks_and_arr(&a, &b, &tmp_arr);
	row_input_sort(&a, &b, &tmp_arr, tmp_size);
	start_push_swap(&a, &b, &tmp_arr, tmp_size);
}
