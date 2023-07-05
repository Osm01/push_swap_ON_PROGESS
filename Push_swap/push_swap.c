/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdid <chdid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:15:12 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/05 16:22:00 by chdid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_stack *stack)
{
	while (stack)
	{
		printf("=>%d\n" ,stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char const *argv[])
{
	t_stack	*t_sa;
	t_stack *t_sb;
	char	**arguments;
	int		i;
	int		y;

	i = 1;
	t_sa = NULL;
	t_sb = NULL;
	while (i < argc)
	{
		arguments = ft_split(argv[i], 32);
		y = 0;
		while (arguments[y])
			ft_lstadd_back(&t_sa, ft_lstnew(ft_atoi(arguments[y++])));
		i ++;
	}
	i = count_elements_alloc(t_sa);
	if (i == 2)
		algo_for_2(&t_sa);
	else if (i == 3)
		algo_for_3(&t_sa);
	else if (i == 4 || i == 5)
		algo_for_5_and_4(&t_sa, t_sb);
	else if (i <= 100)
		algo_for_100(&t_sa, t_sb);
	printf("\n--------Display A------\n");
	display(t_sa);
	return (0);
}
