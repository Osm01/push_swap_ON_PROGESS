#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# include "get_next_line.h"
int		ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);
void    read_operation_and_execute_them(t_stack **stack_a, t_stack **stack_b);
#endif 