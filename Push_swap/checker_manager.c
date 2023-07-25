/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:07:06 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/25 15:21:23 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_is_stack_order(t_stack *stack_a)
{
	int	moves;

	moves = count_move_to_do(stack_a);
	while (moves --)
	{
		while (stack_a)
		{
			if (stack_a->next && stack_a->value > stack_a->next->value)
			{
				ft_printf("KO\n");
				exit(EXIT_FAILURE);
			}
			stack_a = stack_a->next;
		}
	}
	ft_printf("OK\n");
	exit(EXIT_SUCCESS);
}

void	execute_operation(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (!ft_strcmp(op, "sa\n"))
		swap(stack_a);
	if (!ft_strcmp(op, "sb\n"))
		swap(stack_b);
	if (!ft_strcmp(op, "ra\n"))
		rotate(stack_a);
	if (!ft_strcmp(op, "rb\n"))
		rotate(stack_b);
	if (!ft_strcmp(op, "rra\n"))
		reverse_rotate(stack_a);
	if (!ft_strcmp(op, "rrb\n"))
		reverse_rotate(stack_b);
	if (!ft_strcmp(op, "pa\n"))
		push(stack_a, stack_b);
	if (!ft_strcmp(op, "pb\n"))
		push(stack_b, stack_a);
	if (!ft_strcmp(op, "rr\n"))
		return (rotate(stack_a), rotate(stack_b));
	if (!ft_strcmp(op, "rrr\n"))
		return (reverse_rotate(stack_a), reverse_rotate(stack_b));
	if (!ft_strcmp(op, "ss\n"))
		return (swap(stack_a), swap(stack_b));
}

void	read_operation_and_execute_them(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	if (!line)
		return (check_is_stack_order((*stack_a)));
	while (line)
	{
		if (ft_strcmp(line, "sa\n") && ft_strcmp(line, "sb\n") && \
		ft_strcmp(line, "ra\n") && ft_strcmp(line, "rb\n") && \
		ft_strcmp(line, "rra\n") && ft_strcmp(line, "rrb\n") \
		&& ft_strcmp(line, "pa\n") && ft_strcmp(line, "pb\n") \
		&& ft_strcmp(line, "rrr\n") && ft_strcmp(line, "rr\n") \
		&& ft_strcmp(line, "ss\n"))
		{
			return (ft_printf("Error\n"), exit(1));
		}
		execute_operation(stack_a, stack_b, line);
		free (line);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return (check_is_stack_order((*stack_a)));
	}
}
