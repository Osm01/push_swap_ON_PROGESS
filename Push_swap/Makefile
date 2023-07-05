NAME = push_swap

CC = cc
CFLAGS = #-Wall -Wextra -Werror -fsanitize=address -g3

SRC = 	push_swap.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_atoi.c \
		ft_lstadd_front_bonus.c ft_swap.c ft_rotate.c ft_reverse_rotate.c ft_push.c \
		ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_unsigned.c ft_convert_hex.c\
		algo_for_3.c algo_for_5_and_4.c algo_for_100.c insertion_sort.c push_to_b.c algo_for_2.c \
		ft_split.c ft_substr.c

OBJ_SRC = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)

clean :
	rm -f $(OBJ_SRC)

fclean : clean
	rm -f $(NAME)

re : fclean all
