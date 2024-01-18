/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:02:08 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/18 22:15:54 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(info_t *info, char **map, void *textures)
{
	int	width;
	int	hight;
	int	i;
	int	j;

	width = 0;
	hight = 0;
	i = 0;
	while (map[i])
	{
		(j = 0, width = 0);
		while (map[i][j] && map[i][j] != '\n')
		{
			put_img(info, textures, width, hight);
			if (map[i][j] == '1' && (i > 0 && i < info->hight) && (j > 0 && j < info->width))
				put_img(info, "textures/wall.xpm", width, hight);
			if (map[i][j] == 'C')
				put_img(info, "textures/coins.xpm", width, hight);
			if (map[i][j] == 'E')
				put_img(info, DOOR_CLOSED, width, hight);
			(j++, width += 32);
		}
		(i++, hight += 32);
	}
}
void	fill_top_bottom(info_t *info)
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

void	fill_right_left(info_t *info)
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

void	 map_drawer(info_t *info)
{
	int		hight;
	int		width;

	hight = 0;
	width = 0;
	fill_map(info, info->map, FLOOR);
	put_img(info, HERO, info->player.px * 32, info->player.py * 32);
	fill_top_bottom(info);
	fill_right_left(info);
	hight = ((info->hight * 32) - 32);
	width = ((info->width * 32) - 32);
	put_img(info, TOP_LEFT, 0, 0);
	put_img(info, TOP_RIGHT, width, 0);
	put_img(info, BOTTOM_LEFT, 0, hight);
	put_img(info, BOTTOM_RIGHT, width, hight);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		info_t	info;

		info.hight_img = 0;
		info.width_img = 0;
		info.map_path = av[1];
		info.coins = 0;
		info.valid = 0;
		info.map = copy_map(info.map_path);
		info.monster.path = copy_map(info.map_path);
		get_map_data(&info);
		name_checker(info.map_path);
		map_checker(info);
		flood_fill(&info);
		info.mlx_ptr = mlx_init();
		info.window = mlx_new_window(info.mlx_ptr, info.width * 32, info.hight * 32, "SO_LONG");
		info.image = mlx_xpm_file_to_image(info.mlx_ptr, "textures/top.xpm", &info.width_img, &info.hight_img);
		map_drawer(&info);
		mlx_hook(info.window, 2, 0, click_manager, &info);
		mlx_hook(info.window, 17, 0, destroy, &info);
		mlx_loop(info.mlx_ptr);
	}
}
