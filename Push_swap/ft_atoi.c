/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:33:29 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/16 11:04:19 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	value;
	int	signe;
	int	i;

	value = 0;
	signe = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
			break ;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				i ++;
			break ;
		}
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + str[i] - '0';
		i ++;
	}
	return (signe * value);
}
