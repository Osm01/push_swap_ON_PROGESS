/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:36:16 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/25 22:15:57 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_b_500(t_stack **stack_a, t_stack **stack_b, \
int *array, t_helper *h)
{
	int	i;
	int	count;

	count = h->end - h->start;
	i = count_move_to_do(*stack_a);
	while (i -- && (*stack_a) && count)
	{
		if ((*stack_a)->value <= array[(h->end) - 1] && \
		(*stack_a)->value > array[(h->end + h->start) / 2])
		{
			count --;
			pb(stack_b, stack_a);
		}
		else if ((*stack_a)->value <= array[(h->end + h->start) / 2] \
		&& (*stack_a)->value >= array[h->start])
		{
			count --;
			pb(stack_b, stack_a);
			rb(stack_b);
		}
		else
			ra(stack_a);
	}
}

void	push_back_to_stack_a_500(t_stack **stack_a, t_stack *stack_b, \
int *ar, t_helper *h)
{
	while (h->max >= 0)
	{
		if (h->prev < 0)
			h->prev = h->max;
		if (h->pp < 0)
			h->pp = h->max;
		h->re = push_a_manager_500(&stack_b, stack_a, ar, h);
		if (h->re == 1)
			h->max = h->max - 1;
		else if (h->re == 0)
			h->max = h->max - 2;
		else
			h->max = h->max - 3;
		h->prev = h->max - 1;
		h->pp = h->prev - 1;
		if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
}

void	init_values(t_helper *h, int size_array)
{
	h->max = size_array - 1;
	h->prev = h->max - 1;
	h->pp = h->prev - 1;
	h->re = 0;
}

void	algo_for_500(t_stack **stack, t_stack *stack_b)
{
	int			*array;
	t_helper	*h;
	int			size_of_arrays;
	int			i;

	stack_b = NULL;
	h = (t_helper *) malloc(sizeof(t_helper));
	size_of_arrays = count_elements_alloc(*stack);
	h->start = 0;
	h->end = size_of_arrays / 8;
	array = sort_in_array(*stack);
	i = 0;
	while (i < 8)
	{
		if (i == 7)
			h->end = size_of_arrays;
		push_to_stack_b_500(stack, &stack_b, array, h);
		h->end += (size_of_arrays / 8);
		h->start += (size_of_arrays / 8);
		i ++;
	}
	init_values(h, size_of_arrays);
	push_back_to_stack_a_500(stack, stack_b, array, h);
	return (free (array), free (h));
}
