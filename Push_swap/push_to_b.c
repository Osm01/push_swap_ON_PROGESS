/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:27:50 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/25 22:16:25 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_move_to_do(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i ++;
		stack = stack->next;
	}
	return (i);
}

int	*set_array(int *a, int start_index, int lenght)
{
	int	*array;
	int	i;

	array = (int *) malloc(sizeof(int) * lenght);
	i = 0;
	while (i < lenght)
		array[i ++] = a[start_index ++];
	return (array);
}

int	**split_array_by_4(int *a, int size_of_array)
{
	int		**split;
	int		i;
	int		start;

	split = (int **)malloc(sizeof(int *) * (4 + 1));
	i = 0;
	start = 0;
	while (i < 4)
	{
		split[i] = set_array(a, start, (size_of_array / 4));
		start += (size_of_array / 4);
		i ++;
	}
	split[i] = 0;
	return (split);
}

int	**split_array_by_9(int *a, int size_of_array)
{
	int		**split;
	int		i;
	int		start;

	split = (int **)malloc(sizeof(int *) * 9);
	i = 0;
	start = 0;
	while (i < 9)
	{
		split[i] = set_array(a, start, (size_of_array / 9));
		start += (size_of_array / 9);
		i ++;
	}
	return (split);
}

void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b, \
int *chunk, int size_of_chunk)
{
	int	i;
	int	count;

	i = 0;
	count = count_move_to_do(*stack_a);
	while (i++ < count)
	{
		if ((*stack_a)->value <= chunk[size_of_chunk - 1] && \
		(*stack_a)->value > chunk[(size_of_chunk - 1) / 2])
			pb(stack_b, stack_a);
		else if ((*stack_a)->value <= chunk[(size_of_chunk - 1) / 2] \
		&& ((*stack_a)->value >= chunk[0]))
		{
			pb(stack_b, stack_a);
			rb(stack_b);
		}
		else
			ra(stack_a);
	}
}
