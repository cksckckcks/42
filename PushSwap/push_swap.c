/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:26:19 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:08:41 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_val_sort(t_stack **stc, int size)
{
	if (size < 2)
		return ;
	if ((*stc)->head->val > (*stc)->head->chil->val)
		swap_stack(stc);
	if (size == 3)
	{
		if ((*stc)->head->val > (*stc)->head->chil->chil->val || \
		(*stc)->head->chil->val > (*stc)->head->chil->chil->val)
		{
			rotate_stack(stc);
			if ((*stc)->head->val > (*stc)->head->chil->val)
				swap_stack(stc);
			reverse_rotate_stack(stc);
			if ((*stc)->head->val > (*stc)->head->chil->val)
				swap_stack(stc);
		}
	}
}

void	push_swap(t_stack **a, t_stack **b, int left, int right)
{
	int	size;
	int	pivot1;
	int	pivot2;

	size = right - left;
	if (size <= 3)
	{
		three_val_sort(a, size);
		return ;
	}
	pivot1 = right - size / 3 * 2;
	pivot2 = right - size / 3;
	divide_three_bucket(a, b, left, right);
	reverse_rotate_stacks(a, b, right - pivot2);
	push_swap(a, b, pivot2, right);
	push_swap2(b, a, pivot1, pivot2);
	push_swap2(b, a, left, pivot1);
}

void	push_swap2(t_stack **a, t_stack **b, int left, int right)
{
	int	size;
	int	pivot1;
	int	pivot2;

	size = right - left;
	pivot1 = left + size / 3;
	pivot2 = left + size / 3 * 2;
	divide_three_bucket2(a, b, left, right);
	push_swap(b, a, pivot2, right);
	reverse_rotate_stacks(a, b, pivot1 - left);
	push_swap(b, a, pivot1, pivot2);
	stack_front_move(b, a, pivot1 - left);
	push_swap(b, a, left, pivot1);
}

void	push_swap3(t_stack **a, t_stack **b, int left, int right)
{
	int	size;
	int	pivot1;
	int	pivot2;

	size = right - left;
	pivot1 = right - size / 3 * 2;
	pivot2 = right - size / 3;
	divide_three_bucket3(a, b, left, right);
	push_swap(a, b, pivot2, right);
	push_swap2(b, a, pivot1, pivot2);
	push_swap2(b, a, left, pivot1);
}

void	start_push_swap(t_stack **a, t_stack **b, int **arr, int size)
{
	quick_sort(arr, 0, size - 1);
	node_index_setting(a, (*arr), size);
	push_swap3(a, b, 0, size);
	free((*arr));
	free_stacks(a, b);
}
