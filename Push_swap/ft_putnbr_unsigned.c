/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdid <chdid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:24:31 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/10 15:06:43 by chdid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *counter)
{
	if (n < 10)
		ft_putchar(n + 48, counter);
	else if ((int)n < 0)
	{
		ft_putchar('-', counter);
		ft_putnbr(-n, counter);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
}
