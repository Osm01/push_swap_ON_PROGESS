NAME = push_swap
NAME_BONUS = checker

CC = cc 
CFLAGS = -Wall -Wextra -Werror #-fsanitize=adress -g3

SRC = 	push_swap.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_atoi.c \
		ft_lstadd_front_bonus.c ft_swap.c ft_rotate.c ft_reverse_rotate.c ft_push.c \
		ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_unsigned.c ft_convert_hex.c\
		algo_for_3.c algo_for_5_and_4.c algo_for_100.c insertion_sort.c push_to_b.c algo_for_2.c \
		ft_split.c ft_substr.c check_errors.c sort_left_stack_a.c algo_for_500.c push_to_a_manager.c\
		leaks_manager.c push_to_a_manager_500.c
S_BONUS = checker.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_atoi.c \
		ft_lstadd_front_bonus.c ft_swap.c ft_rotate.c ft_reverse_rotate.c ft_push.c \
		ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_unsigned.c ft_convert_hex.c \
		ft_split.c ft_substr.c check_errors.c get_next_line.c get_next_line_utils.c checker_manager.c\
		strcmp.c push_to_b.c leaks_manager.c

OBJ_SRC = $(SRC:.c=.o)
OBJ_BONUS = $(S_BONUS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean :
	rm -f $(OBJ_SRC) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all
