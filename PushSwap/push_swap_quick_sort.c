/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quick_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:51:52 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:23:25 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int **arr, int index1, int index2)
{
	int	tmp;

	tmp = (*arr)[index1];
	(*arr)[index1] = (*arr)[index2];
	(*arr)[index2] = tmp;
}

void	quick_sort(int **arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	if (left >= right)
		return ;
	pivot = left;
	i = left + 1;
	j = right;
	while (i <= j)
	{
		while (i <= right && (*arr)[pivot] > (*arr)[i])
			i++;
		while (j > left && (*arr)[pivot] < (*arr)[j])
			j--;
		if (i > j)
			swap(arr, pivot, j);
		else
			swap(arr, i, j);
	}
	quick_sort(arr, left, j - 1);
	quick_sort(arr, j + 1, right);
}

void	node_index_setting(t_stack **stc, int *arr, int size)
{
	t_node	*tmp;
	int		i;

	tmp = (*stc)->head;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->val == arr[i])
			{
				tmp->idx = i;
				break ;
			}
			i++;
		}
		tmp = tmp->chil;
	}
}
