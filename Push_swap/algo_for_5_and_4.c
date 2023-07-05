/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdid <chdid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:43:15 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/30 16:53:51 by chdid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_move_to_get_min(t_stack *stack_a)
{
	int	min_stack;
	int		count;
	int		i;

	count = 0;
	i = 0;
	min_stack = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value < min_stack)
		{
			min_stack = stack_a->value;
			count = i;
		}
		stack_a = stack_a->next;
		i ++;
	}
	return (count);
}

void	find_min_and_push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = count_move_to_get_min(*stack_a);
	while (count --)
		ra(stack_a);
	pb(stack_b, stack_a);
}

void	algo_for_5_and_4(t_stack **stack, t_stack *stack_b)
{
	int	count;
	int	move_to_do;

	count = count_move_to_do(*stack);
	if (count == 4)
		move_to_do = 1;
	else if (count == 5)
		move_to_do = 2;
	while (move_to_do --)
		find_min_and_push_to_b(stack, &stack_b);
	algo_for_3(stack);
	count = count_move_to_do(stack_b);
	while (count --)
		pa(stack, &stack_b);
}
