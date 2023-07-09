/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:03:40 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/09 17:14:28 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

    last = NULL;
    first = NULL;
	if (!stack || !(*stack))
		return ;
	last = ft_lstlast(*stack);
	first = (*stack);
	if (!first || !last)
		return ;
	(*stack) = last;
	last->next = first;
	last->prev->next = NULL;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}
