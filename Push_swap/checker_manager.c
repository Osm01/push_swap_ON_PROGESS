
#include "checker.h"

void    read_operation_and_execute_them(t_stack **stack_a, t_stack **stack_b)
{
    char	*line;

	(void)stack_a;
	(void)stack_b;
	line = get_next_line(0);
	while (line)
	{
		write(1, line, ft_strlenn(line));
		if (ft_strcmp(line, "sa\n") && ft_strcmp(line, "sb\n") && ft_strcmp(line, "ra\n") \
		&& ft_strcmp(line, "rb\n") && ft_strcmp(line, "rra\n") && ft_strcmp(line, "rrb\n") \
		&& ft_strcmp(line, "pa\n") && ft_strcmp(line, "pb\n"))
		{
			return (ft_printf("Error\n"), exit(1));
		}
		
	}
	
}