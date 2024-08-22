/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_row_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:50:05 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 20:07:53 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_min_idx(t_stack **stc)
{
	int		min;
	int		ret;
	int		idx;
	t_node	*tmp;

	tmp = (*stc)->head;
	min = tmp->val;
	idx = 0;
	ret = idx;
	while (tmp)
	{
		if (min > tmp->val)
		{
			min = tmp->val;
			ret = idx;
		}
		tmp = tmp->chil;
		idx++;
	}
	return (ret);
}

void	min_value_push(t_stack **a, t_stack **b, int sign)
{
	int		idx;

	idx = check_min_idx(a);
	if (idx < 3)
		while (idx--)
			rotate_stack(a);
	else
	{
		while (5 - idx - sign)
		{
			reverse_rotate_stack(a);
			idx++;
		}
	}
	push_stack(b, a);
}

void	five_input_sort(t_stack **a, t_stack **b)
{
	min_value_push(a, b, 0);
	min_value_push(a, b, 1);
	three_input_sort(a);
	push_stack(a, b);
	push_stack(a, b);
	if ((*a)->head->val > (*a)->head->chil->val)
		swap_stack(a);
}

void	three_input_sort(t_stack **stc)
{
	int	one;
	int	two;
	int	three;

	one = (*stc)->head->val;
	two = (*stc)->head->chil->val;
	three = (*stc)->tail->val;
	if (one < two && two > three && one < three)
	{
		swap_stack(stc);
		rotate_stack(stc);
	}
	else if (one > two && one < three)
		swap_stack(stc);
	else if (one < two && two > three && one > three)
		reverse_rotate_stack(stc);
	else if (one > two && one > three && two > three)
	{
		swap_stack(stc);
		reverse_rotate_stack(stc);
	}
	else if (one > two && one > three && two < three)
		rotate_stack(stc);
}

void	row_input_sort(t_stack **a, t_stack **b, int **arr, int input_size)
{
	if (input_size == 2)
	{
		if ((*a)->head->val > (*a)->head->chil->val)
			swap_stack(a);
		free_arr(arr);
		free_stacks(a, b);
	}
	if (input_size == 3)
	{
		three_input_sort(a);
		free_arr(arr);
		free_stacks(a, b);
	}
	else if (input_size == 5)
	{
		five_input_sort(a, b);
		free_arr(arr);
		free_stacks(a, b);
	}
}
