/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdid <chdid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:07:48 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/30 13:20:33 by chdid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_stack_a(t_stack **stack_a, t_stack *stack_b, \
int **chunks, int size_of_chunk)
{
	int	i;
	int	index_current_max;
	int	index_current_max_prev;
	int	re;

	i = 3;
	sort_left_stack_a(stack_a, stack_b);
	while (i >= 0)
	{
		index_current_max = size_of_chunk - 1;
		index_current_max_prev = index_current_max - 1;
		while (index_current_max >= 0)
		{
			if (index_current_max_prev < 0)
				index_current_max_prev = 0;
			re = handle_instruction_push_to_a(&stack_b, stack_a, \
			chunks[i][index_current_max], chunks[i][index_current_max_prev]);
			if (re != chunks[i][index_current_max])
			{
				index_current_max_prev = index_current_max;
				handle_instruction_push_to_a(&stack_b, stack_a, \
				chunks[i][index_current_max], \
				chunks[i][index_current_max_prev]);
				index_current_max = index_current_max - 2;
				index_current_max_prev = index_current_max - 1;
			}
			else
			{
				index_current_max = index_current_max - 1;
				index_current_max_prev = index_current_max - 1;
			}
			if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
		}
		i --;
	}
}

void	algo_for_100(t_stack **stack, t_stack *stack_b)
{
	int		*array;
	int		**split_array_chunks;
	int		size_of_arrays;
	int		i;

	stack_b = NULL;
	array = sort_in_array(*stack);
	size_of_arrays = count_elements_alloc(*stack);
	split_array_chunks = split_array_by_4(array, size_of_arrays);
	i = 0;
	while (i < 4)
	{
		push_to_stack_b(stack, &stack_b, split_array_chunks[i ++], \
		(size_of_arrays / 4));
	}
	push_back_to_stack_a(stack, stack_b, split_array_chunks, \
	(size_of_arrays / 4));
	free(array);
	free_double_point_array(split_array_chunks, 4);
}
