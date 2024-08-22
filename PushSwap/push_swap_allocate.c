/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_allocate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:51:08 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:03:37 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(char c)
{
	t_stack	*ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->head = NULL;
	ret->tail = NULL;
	ret->size = 0;
	ret->name = c;
	return (ret);
}

int	*array_allocate(int size)
{
	int	*ret;

	ret = (int *)malloc(sizeof(int) * size);
	return (ret);
}

void	stack_allocate(t_stack **a, t_stack **b, char c1, char c2)
{
	(*a) = new_stack(c1);
	if (!(*a))
		print_error("Error");
	(*b) = new_stack(c2);
	if (!(*b))
	{
		free(*a);
		print_error("Error");
	}
}
