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

void	display_nor(t_stack *stack)
{
	while (stack)
	{
		printf("%d, ",stack->value);
		stack = stack->next;
	}
	printf("\n--------------|STACK|---------------\n");
}

int	count_move_to_do_from_top(t_stack *stack_b, int value_to_searsh)
{
	int	count;

	count = 0;
	while (stack_b)
	{
		if (stack_b->value == value_to_searsh)
			break ;
		count ++;
		stack_b = stack_b->next;
	}
	return (count);
}

void	sort_left_stack_a(t_stack **stack_a, t_stack *stack_b)
{
	int count;

	count = count_move_to_do(*stack_a);
	if (count == 2)
		algo_for_2(stack_a);
	else if (count == 3)
		algo_for_3(stack_a);
	else if (count == 5)
		algo_for_5_and_4(stack_a, stack_b);
}

void	move_stack_b_to_push_to_a(t_stack **stack_b, t_stack **stack_a, int top_count_to_max, int button_count_to_max)
{
	if (top_count_to_max < button_count_to_max)
	{
		while (top_count_to_max --)
			rb(stack_b);
	}
	else
	{
		while (button_count_to_max --)
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
}

void	handle_instruction_push_to_a(t_stack **stack_b, t_stack **stack_a, int max, int max_prev)
{
	int top_count_to_max;
	int button_count_to_max;
	int top_count_to_max_prev;
	int button_count_to_max_prev;

	top_count_to_max = count_move_to_do_from_top(*stack_b, max);
	button_count_to_max = count_move_to_do(*stack_b) - top_count_to_max;
	top_count_to_max_prev = count_move_to_do_from_top(*stack_b, max_prev);
	button_count_to_max_prev = count_move_to_do(*stack_b) - top_count_to_max_prev;
	if (top_count_to_max < top_count_to_max_prev)
		move_stack_b_to_push_to_a(stack_b, stack_a,top_count_to_max, button_count_to_max);
	else
		move_stack_b_to_push_to_a(stack_b, stack_a,top_count_to_max_prev, button_count_to_max_prev);
}

void	push_back_to_stack_a(t_stack **stack_a, t_stack *stack_b, \
int **chunks, int size_of_chunk)
{
	int	i;
	int	index_current_max;
	int	index_current_max_prev;

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
			handle_instruction_push_to_a(&stack_b, stack_a, chunks[i][index_current_max], chunks[i][index_current_max_prev]);
			index_current_max = index_current_max - 1;
			index_current_max_prev = index_current_max - 1;
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

	i = 0;
	stack_b = NULL;
	array = sort_in_array(*stack);
	size_of_arrays = count_elements_alloc(*stack);
	split_array_chunks = split_array(array, size_of_arrays, (*stack));
	while (i < 4)
	{
		push_to_stack_b(stack, &stack_b, split_array_chunks[i ++], \
		(size_of_arrays / 4));
	}
	push_back_to_stack_a(stack, stack_b, split_array_chunks, \
	(size_of_arrays / 4));
}
