/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:05:39 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/19 20:33:12 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if ((*src))
	{
		tmp = (*src);
		ft_lstadd_front(dst, ft_lstnew((*src)->value));
		(*src)->prev = NULL;
		(*src) = (*src)->next;
		free (tmp);
	}
}

void	pa(t_stack **dst, t_stack **src)
{
	push(dst, src);
	ft_printf("pa\n");
}

void	pb(t_stack **dst, t_stack **src)
{
	push(dst, src);
	ft_printf("pb\n");
}
