/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_left_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdid <chdid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:19:41 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/11 02:07:46 by chdid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_left_stack_a(t_stack **stack_a, t_stack *stack_b)
{
	int	count;

	count = count_move_to_do(*stack_a);
	if (count == 0 || count == 1)
		return ;
	if (count == 2)
		algo_for_2(stack_a);
	else if (count == 3)
		algo_for_3(stack_a);
	else if (count == 5 || count == 4)
		algo_for_5_and_4(stack_a, stack_b);
}
