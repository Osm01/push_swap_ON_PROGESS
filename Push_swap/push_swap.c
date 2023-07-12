/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdid <chdid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:15:12 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/12 15:42:16 by chdid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	while ((*stack_a))
	{
		tmp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		free (tmp);
	}
	while ((*stack_b))
	{
		tmp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		free (tmp);
	}
}

int main(int argc, char const *argv[])
{
	t_stack *t_sa;
	t_stack *t_sb;
	char **arguments;
	int i;
	int y;

	i = 1;
	t_sa = NULL;
	t_sb = NULL;
	if (check_integer(argc, argv) || argc == 1)
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
	i = count_elements_alloc(t_sa);
	if (i == 2)
		algo_for_2(&t_sa);
	else if (i == 3)
		algo_for_3(&t_sa);
	else if (i == 4 || i == 5)
		algo_for_5_and_4(&t_sa, t_sb);
	else if (i <= 100)
		algo_for_100(&t_sa, t_sb);
	else if (i <= 500)
		algo_for_500(&t_sa, t_sb);
	//free_all_stack(&t_sa, &t_sb);
	return (EXIT_SUCCESS);
}
