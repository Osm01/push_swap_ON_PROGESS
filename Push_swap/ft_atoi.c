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

int long	ft_atoi(const char *str)
{
	int long	value;
	int long	signe;
	int			i;

	value = 0;
	signe = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 32 || str[i] == '+' || str[i] == '\t')
			i ++ ;
		if (str[i] == '-')
		{
			signe = -1;
			i ++;
		}
		break ;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + str[i] - '0';
		i ++;
	}
	return (signe * value);
}
