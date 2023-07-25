/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:11:35 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/25 22:00:32 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_element_of_array(int *a, int i, int y)
{
	int	tmp;

	tmp = a[i];
	a[i] = a[y];
	a[y] = tmp;
}

int	count_elements_alloc(t_stack *stack)
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

int	find_min_to_swap(int *a, int start, int end)
{
	int	i;
	int	y;

	i = start;
	y = i;
	while (i < end)
	{
		if (a[i] < a[y])
			y = i;
		i ++;
	}
	return (y);
}

int	*sort_in_array(t_stack *stack)
{
	int		i;
	int		*array;
	int		count;
	int		y;

	i = 0;
	count = count_elements_alloc(stack);
	array = (int *) malloc(sizeof(int) * (count));
	while (i < count && stack)
	{
		array[i ++] = stack->value;
		stack = stack->next;
	}
	i = 0;
	y = 0;
	while (i < count)
	{
		y = find_min_to_swap(array, i, count);
		swap_element_of_array(array, i, y);
		i ++;
	}
	return (array);
}
