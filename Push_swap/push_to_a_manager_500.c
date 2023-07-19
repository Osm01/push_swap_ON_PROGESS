/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a_manager_500.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:10:23 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/19 22:11:08 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pushing_from_top(t_stack **stack_b, t_stack **stack_a, \
int *ar, t_helper *h)
{
	if ((h->t_max < h->t_prev && h->t_max < h->t_pp) \
	|| (h->max == h->prev && h->max == h->pp))
		return (push_to_a(stack_b, stack_a, h->t_max, h->b_max), 1);
	else if (h->t_prev < h->t_max && h->t_prev < h->t_pp)
	{
		push_to_a(stack_b, stack_a, h->t_prev, h->b_prev);
		if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		return (push_a_manager(stack_b, stack_a, ar[h->max], ar[h->max]), 0);
	}
	else
	{
		push_to_a(stack_b, stack_a, h->t_pp, h->b_pp);
		if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		push_a_manager(stack_b, stack_a, ar[h->max], ar[h->max]);
		if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		return (push_a_manager(stack_b, stack_a, ar[h->prev], ar[h->prev]), -1);
	}
}

int	pushing_from_button(t_stack **stack_b, t_stack **stack_a, \
int *ar, t_helper *h)
{
	if ((h->b_max < h->b_prev && h->b_max < h->b_pp) \
	|| (h->max == h->prev && h->max == h->pp))
		return (push_to_a(stack_b, stack_a, h->t_max, h->b_max), 1);
	else if (h->b_prev < h->b_max && h->b_prev < h->b_pp)
	{
		push_to_a(stack_b, stack_a, h->t_prev, h->b_prev);
		if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		return (push_a_manager(stack_b, stack_a, ar[h->max], ar[h->max]), 0);
	}
	else
	{
		push_to_a(stack_b, stack_a, h->t_pp, h->b_pp);
		if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		push_a_manager(stack_b, stack_a, ar[h->max], ar[h->max]);
		if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		return (push_a_manager(stack_b, stack_a, ar[h->prev], ar[h->prev]), -1);
	}
}

int	push_a_manager_500(t_stack **stack_b, t_stack **stack_a, \
int *ar, t_helper *h)
{
	h->t_max = count_move_to_do_from_top(*stack_b, ar[h->max]);
	h->b_max = count_move_to_do(*stack_b) - h->t_max;
	h->t_prev = count_move_to_do_from_top(*stack_b, ar[h->prev]);
	h->b_prev = count_move_to_do(*stack_b) - h->t_prev;
	h->t_pp = count_move_to_do_from_top(*stack_b, ar[h->pp]);
	h->b_pp = count_move_to_do(*stack_b) - h->t_pp;
	if ((h->t_max <= h->b_max) || (h->t_prev <= h->b_prev) \
	|| (h->t_pp < h->b_pp))
		return (pushing_from_top(stack_b, stack_a, ar, h));
	else
		return (pushing_from_button(stack_b, stack_a, ar, h));
}
