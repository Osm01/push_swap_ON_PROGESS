/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:16:17 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/27 12:19:37 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_for_4(t_stack **stack, t_stack *stack_b)
{
	pb(&stack_b, stack);
	algo_for_3(stack);
	pa(stack, &stack_b);
	if ((*stack)->value > (*stack)->next->value && (*stack)->value > (*stack)->next->next->value)
		ra(stack);
	else if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}
