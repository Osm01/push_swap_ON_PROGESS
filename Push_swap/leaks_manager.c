/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:14:13 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/13 20:14:20 by ouidriss         ###   ########.fr       */
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