/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:14:13 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/20 20:06:39 by ouidriss         ###   ########.fr       */
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

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		i ++;
	}
	free (array);
}
