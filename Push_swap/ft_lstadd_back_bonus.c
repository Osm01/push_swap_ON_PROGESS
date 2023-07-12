/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdid <chdid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:06:39 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/12 15:00:53 by chdid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_add;

	if (!new)
		return ;
	if (lst && *lst)
	{
		last_add = ft_lstlast(*lst);
		new->next = NULL;
		last_add->next = new;
		last_add->next->prev = last_add;
	}
	else
	{
		(*lst) = new;
		(*lst)->prev = NULL;
		new->next = NULL;
	}
}
