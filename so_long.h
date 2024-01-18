/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:36:09 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/18 05:14:57 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SO_LONG_H_
# define _SO_LONG_H_

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <mlx.h>

# define FLOOR "textures/floor.xpm"
# define TOP_LEFT "textures/top_left.xpm"
# define TOP_RIGHT "textures/top_right.xpm"
# define BOTTOM_LEFT "textures/bottom_left.xpm"
# define BOTTOM_RIGHT "textures/bottom_right.xpm"
# define HERO "textures/hero.xpm"
# define TOP "textures/top_bottom.xpm"
# define MONSTER_TO_RIGHT "textures/monster_to_right.xpm"
# define MONSTER_TO_LEFT "textures/monster_to_left.xpm"
# define MONSTER_TO_BTM "textures/monster_to_bottom.xpm"
# define MONSTER_TO_TOP "textures/monster_to_top.xpm"
# define DOOR_OPNED "textures/door_opned.xpm"
# define DOOR_CLOSED "textures/door_closed.xpm"
# define PLYR_TLFT "textures/player_to_left.xpm"
# define PLYR_TRGT "textures/player_to_right.xpm"
# define PLYR_TLUP "textures/player_to_top.xpm"
# define PLYR_TLDW "textures/player_to_down.xpm"

typedef struct player_s {
	int		score;
	int		dx;
	int		dy;
	int		px;
	int		py;
} player_t;

typedef struct monster_s {
	int	x;
	int	y;
} monster_t;

typedef struct info_s {
	void		*mlx_ptr;
	void		*window;
	char		*map_path;
	int			width;
	int			hight;
	void		*image;
	char		**map;
	int			width_img;
	int			hight_img;
	int			coins;
	int			valid;
	size_t		counter;
	player_t	player;
	monster_t	monster;
} info_t;


void	show_message(char *message, int ret);
void	get_win_info(info_t *mlx_data);
void	mem_free(char **map);
int		click_manager(int key_code, info_t *mlx_data);
int		destroy(void *ptr);
void	name_checker(char *map_name);
void	map_checker(info_t mlx_data);
size_t	map_size(int fd);
char	**copy_map(char *map_path);
int		open_file(char *file_path);
void	*get_img(char *textuer_path, info_t *mlx_data);
void	put_img(info_t *mlx_data, void *textuer_path, int x, int y);
void	fill_map(info_t *mlx_data, char **map, void *textures);
void	get_map_data(info_t *mlx_data);
// void	get_coin_count(info_t *mlx_data);
void	map_drawer(info_t *mlx_data);
// int		check_point(char **map, int x, int y, int c);
int		_monster(info_t *info);
void	flood_fill(info_t *info);
void	follow_me(info_t *info);
void	to_top(info_t *mlx_data);
void	to_down(info_t *mlx_data);
void	to_left(info_t *mlx_data);
void	to_right(info_t *mlx_data);
void	animate_to_top(info_t *info, void *_char, int *x, int *y);
void	animate_to_down(info_t *info, void *_char, int *x, int *y);
void	animate_to_right(info_t *info, void *_char, int *x, int *y);
void	animate_to_left(info_t *info, void *_char, int *x, int *y);


#endif