/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:53:35 by chjeong           #+#    #+#             */
/*   Updated: 2024/07/28 16:53:36 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*par;
	struct s_node	*chil;
}	t_node;

typedef struct s_stack
{
	char	name;
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

int		check_digit(char *str);
int		check_integer(long long n);
int		check_min_idx(t_stack **stc);
int		check_input_size(char **input);
int		char_to_integer(char *str, int *n);
int		check_input_sort(int *input, int size);
int		stack_pop_back(t_stack **stc, int *save);
int		stack_pop_front(t_stack **stc, int *save);
int		input_dup_check(int *arr, int idx, int n);
int		*array_allocate(int size);
int		*put_input(t_stack **stc, char **input, int size, int sign);
void	print_error(char *str);
void	free_input(char	**input);
void	swap_stack(t_stack **stc);
void	free_stack(t_stack **stc);
void	rotate_stack(t_stack **stc);
void	three_input_sort(t_stack **stc);
void	reverse_rotate_stack(t_stack **stc);
void	free_stacks(t_stack **a, t_stack **b);
void	three_val_sort(t_stack **stc, int size);
void	swap(int **arr, int index1, int index2);
void	free_and_error(t_stack **a, t_stack **b);
void	five_input_sort(t_stack **a, t_stack **b);
void	push_stack(t_stack **stc1, t_stack **stc2);
void	quick_sort(int **arr, int left, int right);
void	stack_push_back(t_stack **stc, int n, int idx);
void	stack_push_front(t_stack **stc, int n, int idx);
void	min_value_push(t_stack **a, t_stack **b, int sign);
void	stack_front_move(t_stack **a, t_stack **b, int size);
void	node_index_setting(t_stack **stc, int *arr, int size);
void	free_stacks_and_arr(t_stack **a, t_stack **b, int **arr);
void	push_swap(t_stack **a, t_stack **b, int left, int right);
void	push_swap2(t_stack **a, t_stack **b, int left, int right);
void	push_swap3(t_stack **a, t_stack **b, int left, int right);
void	reverse_rotate_stacks(t_stack **a, t_stack **b, int size);
void	stack_allocate(t_stack **a, t_stack **b, char c1, char c2);
void	start_push_swap(t_stack **a, t_stack **b, int **arr, int size);
void	divide_three_bucket(t_stack **a, t_stack **b, int left, int right);
void	divide_three_bucket2(t_stack **a, t_stack **b, int left, int right);
void	divide_three_bucket3(t_stack **a, t_stack **b, int left, int right);
void	row_input_sort(t_stack **a, t_stack **b, int **arr, int input_size);
void	*free_arr(int **arr);
t_stack	*new_stack(char c);
#endif