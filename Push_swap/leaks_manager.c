/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:14:13 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/19 20:35:36 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_double_point_array(int **array, int nummber_chunk)
{
	int	i;

	i = 0;
	while (i < nummber_chunk)
	{
		free (array[i]);
		i ++;
	}
	free (array);
}
