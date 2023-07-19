/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:07:06 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/14 21:59:44 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# include "get_next_line.h"

int		ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);
void	read_operation_and_execute_them(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **dst, t_stack **src);
#endif 