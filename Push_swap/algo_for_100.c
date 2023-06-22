/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:07:48 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/22 12:35:03 by ouidriss         ###   ########.fr       */
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
	printf("\n--------Dsiplay B NO ||---------\n");
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

void	push_back_to_stack_a(t_stack **stack_a, t_stack *stack_b, \
int **chunks, int size_of_chunk)
{
	int	top_count = 0;
	int	button_count = 0;
	int	i;
	int	index_current_max;
	int	index_current_max_prev;

	i = 3;
	while (i >= 0)
	{
		index_current_max = size_of_chunk - 1;
		while (index_current_max >= 0)
		{
			printf("\n-------------|STACK A|------------\n");
			display_nor(*stack_a);
			top_count = count_move_to_do_from_top(stack_b, \
			chunks[i][index_current_max]);
			button_count = count_move_to_do(stack_b) - top_count;
			if (top_count > button_count)
				while (button_count --)
					rrb(&stack_b);
			else
				while (top_count --)
					rb(&stack_b);
			pa(stack_a, &stack_b);
			index_current_max --;
		}
		i --;
	}
}

void	algo_for_100(t_stack **stack)
{
	t_stack	*stack_b;
	int		*array;
	int		**split_array_chunks;
	int		size_of_arrays;
	int		i;

	i = 0;
	stack_b = NULL;
	array = sort_in_array(*stack);
	size_of_arrays = count_elements_alloc(*stack);
	split_array_chunks = split_array(array, size_of_arrays);
	while (i < 4)
	{
		push_to_stack_b(stack, &stack_b, split_array_chunks[i ++], \
		(size_of_arrays / 4));
	}
	push_back_to_stack_a(stack, stack_b, split_array_chunks, \
	(size_of_arrays / 4));
}
