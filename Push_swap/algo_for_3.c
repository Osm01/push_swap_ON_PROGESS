/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:25:26 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/16 16:38:38 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_for_3(t_stack **stack)
{
	t_stack	*last;

	last = ft_lstlast(*stack);
	if (last->value > (*stack)->value && last->value > (*stack)->next->value)
		if ((*stack)->value > (*stack)->next->value)
			return (sa(stack));
	if (last->value < (*stack)->value && last->value < (*stack)->next->value)
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
		return (rra(stack));
	}
	if ((*stack)->value > (*stack)->next->value \
	&& last->value > last->prev->value)
		return (ra((stack)));
	if ((*stack)->value < (*stack)->next->value \
	&& last->value < last->prev->value)
		return (sa(stack), ra(stack));
}
