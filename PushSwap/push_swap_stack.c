/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:50:05 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 20:07:53 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push_front(t_stack **stc, int n, int idx)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		print_error("Error");
	new->val = n;
	new->par = NULL;
	new->chil = (*stc)->head;
	new->idx = idx;
	if ((*stc)->head != NULL)
		(*stc)->head->par = new;
	else
		(*stc)->tail = new;
	(*stc)->head = new;
	((*stc)->size)++;
}

void	stack_push_back(t_stack **stc, int n, int idx)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit(1);
	if ((*stc)->tail == NULL)
	{
		new->par = NULL;
		(*stc)->head = new;
		(*stc)->tail = new;
	}
	else
	{
		new->par = (*stc)->tail;
		(*stc)->tail->chil = new;
	}
	new->chil = NULL;
	new->val = n;
	new->idx = idx;
	((*stc)->size)++;
	(*stc)->tail = new;
}

int	stack_pop_front(t_stack **stc, int *save)
{
	t_node	*tmp;
	int		ret;

	tmp = (*stc)->head;
	*save = tmp->idx;
	(*stc)->head = tmp->chil;
	if ((*stc)->head != NULL)
		(*stc)->head->par = NULL;
	else
		(*stc)->tail = NULL;
	ret = tmp->val;
	((*stc)->size)--;
	free(tmp);
	return (ret);
}

int	stack_pop_back(t_stack **stc, int *save)
{
	t_node	*tmp;
	int		ret;

	tmp = (*stc)->tail;
	*save = tmp->idx;
	if (tmp->par != NULL)
	{
		(*stc)->tail = tmp->par;
		(*stc)->tail->chil = NULL;
	}
	else
	{
		(*stc)->head = NULL;
		(*stc)->tail = NULL;
	}
	ret = tmp->val;
	((*stc)->size)--;
	free(tmp);
	return (ret);
}

void	stack_front_move(t_stack **a, t_stack **b, int size)
{
	t_node	*tmp;

	tmp = (*b)->head;
	while (tmp && size--)
		push_stack(a, b);
}
