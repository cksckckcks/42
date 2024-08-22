/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:49:37 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:12:52 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stc)
{
	int	tmp;

	if ((*stc)->size >= 2)
	{
		tmp = (*stc)->head->val;
		(*stc)->head->val = (*stc)->head->chil->val;
		(*stc)->head->chil->val = tmp;
	}
	write(1, "s", 1);
	write(1, &((*stc)->name), 1);
	write(1, "\n", 1);
}

void	push_stack(t_stack **stc1, t_stack **stc2)
{
	int	idx;
	int	n;

	if ((*stc2)->size >= 1)
	{
		n = stack_pop_front(stc2, &idx);
		stack_push_front(stc1, n, idx);
	}
	write(1, "p", 1);
	write(1, &((*stc1)->name), 1);
	write(1, "\n", 1);
}

void	rotate_stack(t_stack **stc)
{
	int	n;
	int	idx;

	n = stack_pop_front(stc, &idx);
	stack_push_back(stc, n, idx);
	write(1, "r", 1);
	write(1, &((*stc)->name), 1);
	write(1, "\n", 1);
}

void	reverse_rotate_stack(t_stack **stc)
{
	int	n;
	int	idx;

	if ((*stc)->size < 2)
		return ;
	n = stack_pop_back(stc, &idx);
	stack_push_front(stc, n, idx);
	write(1, "rr", 2);
	write(1, &((*stc)->name), 1);
	write(1, "\n", 1);
}

void	reverse_rotate_stacks(t_stack **a, t_stack **b, int size)
{
	int	n;
	int	idx;

	while (size--)
	{
		n = stack_pop_back(a, &idx);
		stack_push_front(a, n, idx);
		n = stack_pop_back(b, &idx);
		stack_push_front(b, n, idx);
		write(1, "rrr\n", 4);
	}
}
