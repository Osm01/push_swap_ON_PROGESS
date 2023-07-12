/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdid <chdid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:58:11 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/12 14:27:27 by chdid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	move_stack_b_to_push_to_a(t_stack **stack_b, t_stack **stack_a, \
int top_count_to_max, int button_count_to_max)
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

int	handle_instruction_push_to_a(t_stack **stack_b, t_stack **stack_a, \
int max, int max_prev)
{
	int	top_count_to_max;
	int	button_count_to_max;
	int	top_count_to_max_prev;
	int	button_count_to_max_prev;
	int	count_elements;

	count_elements = count_move_to_do(*stack_b);
	top_count_to_max = count_move_to_do_from_top(*stack_b, max);
	button_count_to_max = count_move_to_do(*stack_b) - top_count_to_max;
	top_count_to_max_prev = count_move_to_do_from_top(*stack_b, max_prev);
	button_count_to_max_prev = count_move_to_do(*stack_b) - \
	top_count_to_max_prev;
	if (top_count_to_max <= (count_elements / 2) || top_count_to_max_prev <= (count_elements / 2))
	{
		if (top_count_to_max < top_count_to_max_prev)
			return (move_stack_b_to_push_to_a(stack_b, stack_a, \
			top_count_to_max, button_count_to_max), max);
		else
			return (move_stack_b_to_push_to_a(stack_b, stack_a, \
			top_count_to_max_prev, button_count_to_max_prev), max_prev);
	}
	else
	{
		if (button_count_to_max < button_count_to_max_prev)
			return (move_stack_b_to_push_to_a(stack_b, stack_a, \
			top_count_to_max, button_count_to_max), max);
		else
			return (move_stack_b_to_push_to_a(stack_b, stack_a, \
			top_count_to_max_prev, button_count_to_max_prev), max_prev);
	}
		
}

