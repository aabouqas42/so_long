/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:02:08 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/22 01:36:04 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_utils/so_long_bonus.h"

void	fill_map(t_info *info, char **map, void *textures)
{
	static int	width;
	static int	hight;
	static int	i;
	static int	j;

	while (map[i])
	{
		j = 0;
		width = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			put_img(info, textures, width, hight);
			if (map[i][j] == '1' && (i > 0
				&& i < info->hight) && (j > 0 && j < info->width))
				put_img(info, "textures/wall.xpm", width, hight);
			if (map[i][j] == 'C')
				put_img(info, "textures/coins.xpm", width, hight);
			if (map[i][j] == 'E')
				put_img(info, CLOSED, width, hight);
			j++;
			width += 32;
		}
		i++;
		hight += 32;
	}
}

void	fill_top_bottom(t_info *info)
{
	int	width;
	int	hight;

	width = 0;
	hight = (info->hight * 32) - 32;
	while (width < (info->width * 32))
	{
		put_img(info, "textures/top_bottom.xpm", width, 0);
		put_img(info, "textures/top_bottom.xpm", width, hight);
		width += 32;
	}
}

void	fill_right_left(t_info *info)
{
	int	width;
	int	hight;

	width = (info->width * 32) - 32;
	hight = 32;
	while (hight < (info->hight * 32))
	{
		put_img(info, "textures/left.xpm", 0, hight);
		put_img(info, "textures/right.xpm", width, hight);
		hight += 32;
	}
	put_img(info, "textures/culomn_top.xpm", 0, 32);
	put_img(info, "textures/culomn_top.xpm", width, 32);
	put_img(info, "textures/culomn_bottom.xpm", 0, hight - 64);
	put_img(info, "textures/culomn_bottom.xpm", width, hight - 64);
}

void	map_drawer(t_info *info)
{
	int		hight;
	int		width;
	int		i;
	int		j;

	fill_map(info, info->map, FLOOR);
	put_img(info, PLYR_TO_BOTTOM, info->plyr.px * 32, info->plyr.py * 32);
	fill_top_bottom(info);
	fill_right_left(info);
	hight = ((info->hight * 32) - 32);
	width = ((info->width * 32) - 32);
	put_img(info, TOP_LEFT, 0, 0);
	put_img(info, TOP_RIGHT, width, 0);
	put_img(info, BOTTOM_LEFT, 0, hight);
	put_img(info, BOTTOM_RIGHT, width, hight);
	i = ((info->width / 2) * 32) - 64;
	j = i + 128;
	while (i <= j)
	{
		put_img(info, BG_SCOORE, i, 0);
		i += 32;
	}
}

int	main(int ac, char *av[])
{
	t_info	info;
	int		width;
	int		hight;

	if (ac == 2)
	{
		_init(&info);
		info.map_path = av[1];
		name_checker(&info);
		info.map = copy_map(&info);
		info.mons.path = copy_map(&info);
		get_map_data(&info);
		map_checker(&info);
		flood_fill(&info);
		hight = info.hight * 32;
		width = info.width * 32;
		info.mlx_ptr = mlx_init();
		info.window = mlx_new_window(info.mlx_ptr, width, hight, "SO_LONG");
		map_drawer(&info);
		mlx_hook(info.window, 2, 0, click_manager, &info);
		mlx_hook(info.window, 17, 0, destroy, &info);
		mlx_loop_hook(info.mlx_ptr, coin_flipper, &info);
		mlx_loop(info.mlx_ptr);
	}
}
