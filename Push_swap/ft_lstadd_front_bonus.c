/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:03:35 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/12 14:15:32 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack	**stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = (*stack);
	if (!new || !stack)
		return ;
	if (!(*stack))
		(*stack) = new;
	else
	{
		new->next = tmp;
		tmp->prev = new;
		(*stack) = new;
	}
	(*stack)->prev = NULL;
}
