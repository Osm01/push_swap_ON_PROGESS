/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdid <chdid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:36:16 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/11 17:56:16 by chdid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_b_500(t_stack **stack_a, t_stack **stack_b, int *array, int start, int chunk)
{
	int	i;
	int	count;
	
	count = chunk - start;
	i = count_move_to_do(*stack_a);
	while (i -- && stack_a && (*stack_a))
	{
		if (count == 0)
			break ;
		if ((*stack_a)->value <= array[chunk - 1] && (*stack_a)->value > array[(chunk + start) / 2] )
		{
			count --;
			pb(stack_b, stack_a);
		}
		else if ((*stack_a)->value <= array[(chunk + start) / 2] && (*stack_a)->value >= array[start])
		{
			count --;
			pb(stack_b, stack_a);
			rb(stack_b);
		}
		else
			ra(stack_a);
	}
}

void	push_back_to_stack_a_500(t_stack **stack_a, t_stack *stack_b, \
int *array, int size_of_array)
{
	int	index_current_max;
	int	index_current_max_prev;
	int	re;

	index_current_max = size_of_array - 1;
	index_current_max_prev = index_current_max - 1;
	while (index_current_max >= 0 )
	{
		if (index_current_max_prev < 0)
			index_current_max_prev = 0;
		re = handle_instruction_push_to_a(&stack_b, stack_a, \
		array[index_current_max], array[index_current_max_prev]);
		if (re != array[index_current_max])
		{
			index_current_max_prev = index_current_max;
			handle_instruction_push_to_a(&stack_b, stack_a, \
			array[index_current_max], array[index_current_max_prev]);
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
}


void	algo_for_500(t_stack **stack, t_stack *stack_b)
{
	int		*array;
	int		size_of_arrays;
	int		chunk;
	int		i;
	int		start;

	stack_b = NULL;
	array = sort_in_array(*stack);

	size_of_arrays = count_elements_alloc(*stack);
	chunk = size_of_arrays / 9;
	start = 0;
	i = 0;
	while (i < 9)
	{
		if (i == 8)
			chunk = size_of_arrays;
		push_to_stack_b_500(stack, &stack_b, array, start, chunk);
		chunk += (size_of_arrays / 9);
		start += (size_of_arrays / 9);
		i ++;
	}
	push_back_to_stack_a_500(stack, stack_b, array, size_of_arrays);
	free (array);
}
