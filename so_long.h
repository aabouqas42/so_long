/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:36:09 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/14 15:07:11 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SO_LONG_H_
# define _SO_LONG_H_

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

typedef struct player {
	int	score;
	int	x;
	int	y;
} player;

typedef struct win_s {
	void	*mlx_ptr;
	void	*window;
	char	*map_path;
	int		width;
	int		hight;
	void	*image;
	char	**map;
	int		width_img;
	int		hight_img;
	int		coins;
	player	_player;
} win_t;


void	show_message(char *message, int ret);
void	get_win_info(win_t *mlx_data);
void	mem_free(char **map);
int		click_manager(int key_code, win_t *mlx_data);
int		destroy(void *ptr);
void	name_checker(char *map_name);
void	map_checker(win_t mlx_data);
size_t	map_size(int fd);
char	**copy_map(char *map_path);
int		open_file(char *file_path);
void	*get_img(char *textuer_path, win_t *mlx_data);
void	put_img(win_t *mlx_data, void *textuer_path, int x, int y);
void	fill_map(win_t *mlx_data, char **map, void *textures);
void	get_player_position(win_t *mlx_data);
void	get_coin_count(win_t *mlx_data);
void	map_drawer(win_t *mlx_data);
void	to_top(win_t *mlx_data);
void	to_down(win_t *mlx_data);
void	to_left(win_t *mlx_data);
void	to_right(win_t *mlx_data);


#endif