/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:43:15 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/21 14:00:51 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_for_5(t_stack **stack)
{
	t_stack	*stack_b;

	pb(&stack_b, stack);
	pb(&stack_b, stack);
	algo_for_3(stack);
	if (stack_b->value < stack_b->next->value)
		sb(&stack_b);
	pa(stack, &stack_b);
	if ((*stack)->value > (*stack)->next->value && \
	(*stack)->value > (*stack)->next->next->value)
		ra(stack);
	else if ((*stack)->value > (*stack)->next->value)
		sa(stack);
	pa(stack, &stack_b);
	if ((*stack)->value > (*stack)->next->value && \
	(*stack)->value > (*stack)->next->next->value)
		return (ra(stack));
	if ((*stack)->value > (*stack)->next->value)
		return (sa(stack));
}
