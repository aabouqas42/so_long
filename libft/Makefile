CC = cc
CFLAGS= -Wextra -Werror -Wall
SRC = $(shell cat src.txt)
SRCBONUS = $(shell cat src_bonus.txt)
NAME = libft.a
OBJ = $(SRC:.c=.o)
BONUSOBJ = $(SRCBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) -c $(CFLAGS) $<

bonus: $(BONUSOBJ)
	ar crs $(NAME) $(BONUSOBJ)

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ) $(BONUSOBJ)

.PHONY : clean fclean
