/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:18:57 by ouidriss          #+#    #+#             */
/*   Updated: 2023/07/19 21:58:04 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "printf.h"
# include <limits.h>

typedef struct stack
{
	int				value;
	struct stack	*next;
	struct stack	*prev;
}				t_stack;
typedef struct helper
{
	int	start;
	int	end;
	int	max;
	int	prev;
	int	pp;
	int	re;
	int	t_max;
	int	t_prev;
	int	t_pp;
	int	b_max;
	int	b_prev;
	int	b_pp;
}				t_helper;

t_stack		*ft_lstnew(int content);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
int long	ft_atoi(const char *str);
void		ft_lstadd_front(t_stack	**stack, t_stack *new);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_a);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **dst, t_stack **src);
void		pb(t_stack **dst, t_stack **src);
void		algo_for_2(t_stack **stack);
void		algo_for_3(t_stack **stack);
void		algo_for_5_and_4(t_stack **stack, t_stack *stack_b);
void		algo_for_100(t_stack **stack, t_stack *t_sb);
void		algo_for_500(t_stack **stack, t_stack *stack_b);
int			ft_printf(const char *str, ...);
int			count_move_to_do(t_stack *stack);
int			*sort_in_array(t_stack *stack);
int			count_elements_alloc(t_stack *stack);
void		push_to_stack_b(t_stack **stack_a, t_stack **stack_b, \
			int *chunk, int size_of_chunk);
int			**split_array_by_4(int *a, int size_of_array);
int			**split_array_by_9(int *a, int size_of_array);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			check_duplicate(t_stack *stack);
int			check_integer(int argc, char const *argv[]);
void		sort_left_stack_a(t_stack **stack_a, t_stack *stack_b);
int			count_move_to_do_from_top(t_stack *stack_b, int value_to_searsh);
void		push_to_a(t_stack **stack_b, t_stack **stack_a, \
			int top_count_to_max, int button_count_to_max);
int			push_a_manager(t_stack **stack_b, t_stack **stack_a, \
			int max, int max_prev);
int			push_a_manager_500(t_stack **stack_b, t_stack **stack_a, \
			int *ar, t_helper *h);
void		free_2d_array(char **array);
void		free_double_point_array(int **array, int nummber_chunk);
void		free_stack(t_stack **stack);

#endif