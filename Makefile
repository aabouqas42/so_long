CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC = so_long.c map_checker.c so_long_utils.c programe_closer.c image_manager.c player_mover.c map_utils.c animator.c
OBJ = $(SRC:.c=.o)
HEADER = so_long.h
NAME = so_long


all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -L libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HEADER)
	make -C libft
	$(CC) $(CFLAGS) -Imlx -c $<

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

.PHONY : all re fclean clean