/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:18:57 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/22 18:33:56 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "printf.h"

typedef struct stack
{
	int	value;
	struct stack 	*next;
	struct stack 	*prev;
}				t_stack;

t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_atoi(const char *str);
void	ft_lstadd_front(t_stack	**stack, t_stack *new);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_a);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	pa(t_stack **dst, t_stack **src);
void	pb(t_stack **dst, t_stack **src);
void	algo_for_3(t_stack **stack);
void	algo_for_5(t_stack **stack);
int		ft_printf(const char *str, ...);
void	algo_for_100(t_stack **stack);
int		count_move_to_do(t_stack *stack);
int		*sort_in_array(t_stack *stack);
int		count_elements_alloc(t_stack *stack);
void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b, \
		int *chunk, int size_of_chunk);
int		**split_array(int *a, int size_of_array);
#endif