/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:07:06 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/14 21:58:34 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	read_operation_and_execute_them(&t_sa, &t_sb);
	return (EXIT_SUCCESS);
}
