CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC = so_long.c map_checker.c so_long_utils.c programe_closer.c image_manager.c player_mover.c
OBJ = $(SRC:.c=.o)
NAME = so_long


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) -c $<
clean:
	make clean -C libft
	rm -f $(OBJ)