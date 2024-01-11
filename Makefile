CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC = so_long.c map_checker.c so_long_utils.c
OBJ = $(SRC:.c=.o)
NAME = so_long


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<
clean:
	make clean -C libft
	rm -f $(OBJ)