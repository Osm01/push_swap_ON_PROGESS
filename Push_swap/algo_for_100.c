/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:07:48 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/17 23:49:27 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_stack_a(t_stack **stack_a, t_stack *stack_b, \
int **chs, int size_of_chunk)
{
	int	i;
	int	max;
	int	prev;

	i = 3;
	while (i >= 0)
	{
		max = size_of_chunk - 1;
		prev = max - 1;
		while (max >= 0)
		{
			if (prev < 0)
				prev = max;
			if (!push_a_manager(&stack_b, stack_a, chs[i][max], chs[i][prev]))
			{
				push_a_manager(&stack_b, stack_a, chs[i][max], chs[i][max]);
				max = max - 1;
			}
			max = max - 1;
			prev = prev - 1;
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
	sort_left_stack_a(stack, stack_b);
	push_back_to_stack_a(stack, stack_b, split_array_chunks, \
	(size_of_arrays / 4));
	free(array);
	free_double_point_array(split_array_chunks, 4);
}
