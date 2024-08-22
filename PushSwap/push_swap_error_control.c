/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_control.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:49:37 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 17:12:52 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

void	free_stack(t_stack **stc)
{
	t_node	*tmp;
	t_node	*tmp2;

	if ((*stc) == NULL)
		return ;
	tmp = (*stc)->head;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->chil;
		free(tmp2);
	}
	free(*stc);
	(*stc) = NULL;
}

void	free_and_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	print_error("Error");
}

void	free_stacks(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	exit(0);
}

void	free_stacks_and_arr(t_stack **a, t_stack **b, int **arr)
{
	free_arr(arr);
	free_stacks(a, b);
}
