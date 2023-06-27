/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:15:12 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/22 12:35:51 by ouidriss         ###   ########.fr       */
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
	int		i;
	int		y;

	i = 1;
	t_sa = NULL;
	t_sb = NULL;
	while (i < argc)
	{

		ft_lstadd_back(&t_sa, ft_lstnew(ft_atoi(argv[i])));
		i ++;
	}
	/*if (argc == 3)
		algo_for_2(&t_sa);
	else if (argc == 4)
		algo_for_3(&t_sa);
	else if (argc == 5)
		algo_for_4(&t_sa, t_sb);
	else if (argc == 6)
		algo_for_5(&t_sa, t_sb);
	else if (argc <= 101)
		algo_for_100(&t_sa, t_sb);*/
	printf("\n--------Display A------\n");
	display(t_sa);
	/*printf("\n--------Display B------\n");
	display(t_sb);
	//-------------------------------------//
	push(&t_sb, &t_sa);
	printf("\n--------PUSH TO B------\n");
	//-------------------------------------//
	printf("\n--------Display------\n");
	display(t_sa);
	printf("\n--------DisplayB------\n");
	display(t_sb);
	//-------------------------------------//
	rotate(&t_sa);
	printf("\n--------ROTATE B------\n");
	//-------------------------------------//
	printf("\n--------Display------\n");
	display(t_sa);
	printf("\n--------Display B------\n");
	display(t_sb);*/
	return (0);
}
