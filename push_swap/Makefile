CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC = ft_atoi.c  ft_split.c  ft_itoa.c  sortin.c  pushing_logic.c\
	sort_lesse_than_x.c pushing_logic2.c check_av.c check_av2.c putBinA.c\
	push_swap.c operatins/ft_push.c  operatins/ft_rotate.c\
	operatins/ft_swap.c operatins/new_stack.c operatins/rules.c operatins/rules2.c

BONUS_SRC = get_next_line.c  get_next_line_utils.c checker.c ft_atoi.c \
	ft_split.c  ft_itoa.c  sortin.c  checker_func.c  pushing_logic.c\
	sort_lesse_than_x.c pushing_logic2.c check_av.c check_av2.c\
	putBinA.c  operatins/ft_push.c  operatins/ft_rotate.c\
	operatins/ft_swap.c operatins/new_stack.c operatins/rules.c operatins/rules2.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

BONUS_NAME = checker


NAME = push_swap


all : $(NAME)

$(NAME) :$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -fsanitize=address -g3 -o $(NAME)

bonus :$(BONUS_NAME)

$(BONUS_NAME) :$(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -fsanitize=address -g3  -o $(BONUS_NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
