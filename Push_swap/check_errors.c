/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:07:06 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/19 20:23:01 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_ischar(int argc, char const *argv[])
{
	int			i;
	int			y;
	int			z;
	char		**arg;

	i = 1;
	while (i < argc)
	{
		y = 0;
		arg = ft_split(argv[i], 32);
		while (arg[y])
		{
			z = 0;
			while (arg[y][z] != '\0')
			{
				if (arg[y][z] < '0' || arg[y][z] > '9')
					return (1);
				z ++;
			}
			y ++;
		}
		free_2d_array(arg);
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
