/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:07:06 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/20 20:37:10 by ouidriss         ###   ########.fr       */
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
					return (free_2d_array(argument), 1);
				z ++;
			}
			y ++;
		}
		free_2d_array(argument);
		i ++;
	}
	return (0);
}

int	ischar(char **arg)
{
	int	i;
	int	y;

	i = 0;
	while (arg[i])
	{
		y = 0;
		while (arg[i][y] != '\0')
		{
			if ((arg[i][y] == '-' || arg[i][y] == '+') && y == 0)
				y ++;
			else
			{
				if ((arg[i][y] == '-' || arg[i][y] == '+') && arg[i][y] == 32)
					return (1);
			}
			if (!(arg[i][y] >= '0' && arg[i][y] <= '9'))
				return (1);
			y ++;
		}
		i ++;
	}
	return (0);
}

int	check_ischar(int argc, char const *argv[])
{
	int			i;
	char		**arg;

	i = 1;
	while (i < argc)
	{
		arg = ft_split(argv[i], 32);
		if (!(*arg))
			return (1);
		if (ischar(arg))
			return (free_2d_array(arg), 1);
		free_2d_array(arg);
		i++;
	}
	return (0);
}

int	check_integer(int argc, char const *argv[])
{
	int			i;
	int			y;
	int long	value;
	char		**arguments;

	if (check_ischar(argc, argv))
		return (1);
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
			if (value > INT_MAX || value < INT_MIN)
				return (free_2d_array(arguments), 1);
			y ++;
		}
		free_2d_array(arguments);
		i ++;
	}
	return (0);
}
