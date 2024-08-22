/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bucket.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:51:08 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:03:37 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_three_bucket(t_stack **a, t_stack **b, int left, int right)
{
	int	size;
	int	pivot1;
	int	pivot2;
	int	i;

	size = right - left;
	pivot1 = right - size / 3 * 2;
	pivot2 = right - size / 3;
	i = 0;
	while (size-- && (*a)->head)
	{
		if ((*a)->head->idx < pivot1)
			push_stack(b, a);
		else if ((*a)->head->idx >= pivot1 && (*a)->head->idx < pivot2)
		{
			push_stack(b, a);
			rotate_stack(b);
		}
		else
			rotate_stack(a);
	}
}

void	divide_three_bucket2(t_stack **a, t_stack **b, int left, int right)
{
	int	size;
	int	pivot1;
	int	pivot2;
	int	i;

	size = right - left;
	pivot1 = left + size / 3;
	pivot2 = left + size / 3 * 2;
	i = 0;
	while (size-- && (*a)->head)
	{
		if ((*a)->head->idx < pivot1)
			rotate_stack(a);
		else if ((*a)->head->idx >= pivot1 && (*a)->head->idx < pivot2)
		{
			push_stack(b, a);
			rotate_stack(b);
		}
		else
			push_stack(b, a);
	}
}

void	divide_three_bucket3(t_stack **a, t_stack **b, int left, int right)
{
	int	size;
	int	pivot1;
	int	pivot2;
	int	i;

	size = right - left;
	pivot1 = right - size / 3 * 2;
	pivot2 = right - size / 3;
	i = 0;
	while (size-- && (*a)->head)
	{
		if ((*a)->head->idx < pivot1)
		{
			push_stack(b, a);
			rotate_stack(b);
		}
		else if ((*a)->head->idx >= pivot1 && (*a)->head->idx < pivot2)
			push_stack(b, a);
		else
			rotate_stack(a);
	}
}
