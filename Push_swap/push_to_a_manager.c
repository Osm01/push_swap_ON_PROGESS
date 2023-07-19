/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:58:11 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/19 22:11:32 by ouidriss         ###   ########.fr       */
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

void	push_to_a(t_stack **stack_b, t_stack **stack_a, \
int top_count_to_max, int button_count_to_max)
{
	if (top_count_to_max <= button_count_to_max)
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

int	push_a_manager(t_stack **stack_b, t_stack **stack_a, \
int max, int max_prev)
{
	int	t_max;
	int	b_max;
	int	t_prev;
	int	b_prev;

	t_max = count_move_to_do_from_top(*stack_b, max);
	b_max = count_move_to_do(*stack_b) - t_max;
	t_prev = count_move_to_do_from_top(*stack_b, max_prev);
	b_prev = count_move_to_do(*stack_b) - t_prev;
	if ((t_max <= b_max) || (t_prev <= b_prev))
	{
		if (t_max < t_prev || max == max_prev)
			return (push_to_a(stack_b, stack_a, t_max, b_max), 1);
		else
			return (push_to_a(stack_b, stack_a, t_prev, b_prev), 0);
	}
	else
	{
		if (b_max < b_prev || max == max_prev)
			return (push_to_a(stack_b, stack_a, t_max, b_max), 1);
		else
			return (push_to_a(stack_b, stack_a, t_prev, b_prev), 0);
	}
}
