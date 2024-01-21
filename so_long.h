/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:36:09 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/21 00:43:11 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# define TOP "textures/top_bottom.xpm"
# define M_TO_R "textures/monster_to_right.xpm"
# define M_TO_L "textures/monster_to_left.xpm"
# define M_TO_B "textures/monster_to_bottom.xpm"
# define M_TO_T "textures/monster_to_top.xpm"
# define OD "textures/door_opned.xpm"
# define CD "textures/door_closed.xpm"
# define PLYR_TLFT "textures/player_to_left.xpm"
# define PLYR_TRGT "textures/player_to_right.xpm"
# define PLYR_TLUP "textures/player_to_top.xpm"
# define PLYR_TLDW "textures/player_to_down.xpm"

typedef struct s_player
{
	int		score;
	int		dx;
	int		dy;
	int		px;
	int		py;
}	t_player;

typedef struct s_monster
{
	char	**path;
	int		x;
	int		y;
}	t_monster;

typedef struct s_info
{
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
	size_t		speed;
	t_player	plyr;
	t_monster	mons;
}	t_info;

void	show_message(t_info *info, char *message, int ret);
void	get_win_info(t_info *info);
void	mem_free(char **map);
int		click_manager(int key_code, t_info *info);
int		destroy(t_info *info);
void	name_checker(t_info *info);
void	map_checker(t_info *info);
size_t	map_size(int fd);
char	**copy_map(t_info *info);
int		open_file(t_info *info);
void	*get_img(char *textuer_path, t_info *info);
void	put_img(t_info *info, void *textuer_path, int x, int y);
void	fill_map(t_info *info, char **map, void *textures);
void	get_map_data(t_info *info);
void	map_drawer(t_info *info);
int		_monster_mover(t_info *info);
void	flood_fill(t_info *info);
void	to_top(t_info *info);
void	to_down(t_info *info);
void	to_left(t_info *info);
void	to_right(t_info *info);
void	a_to_t(t_info *info, void *_char, int *x, int *y);
void	a_to_d(t_info *info, void *_char, int *x, int *y);
void	a_to_r(t_info *info, void *_char, int *x, int *y);
void	a_to_l(t_info *info, void *_char, int *x, int *y);
void	anim(t_info *info);
void	_init(t_info *info);

#endif