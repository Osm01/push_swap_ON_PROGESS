/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:15:12 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/19 20:06:11 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_empty_arg(int argc)
{
	if (argc == 1)
		exit(EXIT_FAILURE);
}

void	check_stack_is_sorted(t_stack *stack_a)
{
	int	moves;

	moves = count_move_to_do(stack_a);
	moves --;
	while (moves --)
	{
		if (stack_a->next && (stack_a->value > stack_a->next->value))
			break ;
		stack_a = stack_a->next;
	}
	if (moves < 0)
		exit(EXIT_FAILURE);
}

void	cases(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = count_elements_alloc(stack_a);
	if (i == 2)
		algo_for_2(&stack_a);
	else if (i == 3)
		algo_for_3(&stack_a);
	else if (i == 4 || i == 5)
		algo_for_5_and_4(&stack_a, stack_b);
	else if (i >= 6 && i <= 100)
		algo_for_100(&stack_a, stack_b);
	else if (i >= 101 && i <= 500)
		algo_for_500(&stack_a, stack_b);
}

int	main(int argc, char const *argv[])
{
	t_stack	*t_sa;
	t_stack	*t_sb;
	char	**arguments;
	int		i;
	int		y;

	i = 1;
	t_sa = NULL;
	t_sb = NULL;
	check_empty_arg(argc);
	if (check_integer(argc, argv))
		return (ft_printf("Error\n"), EXIT_FAILURE);
	while (i < argc)
	{
		arguments = ft_split(argv[i], 32);
		y = 0;
		while (arguments[y])
			ft_lstadd_back(&t_sa, ft_lstnew(ft_atoi(arguments[y++])));
		free_2d_array(arguments);
		i++;
	}
	if (check_duplicate(t_sa))
		return (ft_printf("Error\n"), EXIT_FAILURE);
	return (check_stack_is_sorted(t_sa), cases(t_sa, t_sb), EXIT_SUCCESS);
}
