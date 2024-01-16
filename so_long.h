/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:36:09 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/16 18:11:42 by aabouqas         ###   ########.fr       */
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
# define DOOR_OPNED "textures/door_opned.xpm"
# define DOOR_CLOSED "textures/door_closed.xpm"

typedef struct player_s {
	int		score;
	int		dx;
	int		dy;
	int		px;
	int		py;
} player_t;

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
	player_t	player;
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
void	get_coin_count(info_t *mlx_data);
void	map_drawer(info_t *mlx_data);
int	check_point(char **map, int x, int y, int c);
void	flood_fill(info_t *info);
void	to_top(info_t *mlx_data);
void	to_down(info_t *mlx_data);
void	to_left(info_t *mlx_data);
void	to_right(info_t *mlx_data);


#endif