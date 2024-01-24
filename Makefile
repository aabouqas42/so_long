# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 21:11:34 by aabouqas          #+#    #+#              #
#    Updated: 2024/01/24 21:05:25 by aabouqas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC = so_long.c utils/map_checker.c utils/so_long_utils.c \
	utils/click_manager.c utils/image_manager.c utils/player_manager.c \
	utils/map_utils.c utils/animator.c
OBJ = $(SRC:.c=.o)
HEADER = utils/so_long.h
NAME = so_long
BONUS = so_long_bonus
LIBFT = libft/libft.a
BONUS_SRC = so_long_bonus.c bonus_utils/map_checker_bonus.c \
	bonus_utils/so_long_utils_bonus.c bonus_utils/click_manager_bonus.c \
	bonus_utils/image_manager_bonus.c bonus_utils/player_manager_bonus.c \
	bonus_utils/map_utils_bonus.c bonus_utils/animator_bonus.c bonus_utils/coin_animator_bonus.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)
HEADER_BONUS = bonus_utils/so_long_bonus.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

utils/%.o: utils/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

bonus_utils/%.o: bonus_utils/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

re: fclean all

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
	rm -f $(BONUS)

clean:
	make clean -C libft
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

.PHONY : clean