cc = gcc
SRC = main.c ft_*
NAME = push_swap
OBJ = $(SRC:.c=.o)

Flags = -Wall -Wextra -Werror


$(NAME): $(OBJ)
	$(CC) $(OBJ) $(Flags) -o $(NAME)


bonus :
	gcc $(Flags) tst.c ft_split.c  ft_calloc.c  ft_atoi.c ft_planarrays.c ft_bzero.c bn_ft_rules* ft_strjoin.c ft_strlen.c ft_putstr_fd.c ft_strncmp.c -o checker

fclean :
	rm -rf $(OBJ) $(NAME)