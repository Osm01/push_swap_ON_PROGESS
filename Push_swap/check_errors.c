/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:29:33 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/06 12:29:49 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (stack)
	{
		if (current->value == stack->value && current != stack)
			return (1);
		stack = stack->next;
		if (stack == NULL && current->next)
		{
			current = current->next;
			stack = current->next;
		}
	}
	return (0);
}

int	check_isfloat(int argc, char const *argv[])
{
	int		i;
	int		y;
	int		z;
	char	**argument;

	i = 1;
	while (i < argc)
	{
		y = 0;
		argument = ft_split(argv[i], 32);
		while (argument[y])
		{
			z = 0;
			while (argument[y][z])
			{
				if (argument[y][z] == ',' || argument[y][z] == '.')
					return (1);
				z ++;
			}
			y ++;
		}
		i ++;
	}
	return (0);
}

int	check_integer(int argc, char const *argv[])
{
	int			i;
	int			y;
	int long	value;
	char		**arguments;

	if (check_isfloat(argc, argv))
		return (1);
	i = 1;
	while (i < argc)
	{
		y = 0;
		arguments = ft_split(argv[i], 32);
		while (arguments[y])
		{
			value = ft_atoi(arguments[y]);
			if (value > INT32_MAX || value < INT32_MIN)
				return (1);
			y ++;
		}
		i ++;
	}
	return (0);
}
