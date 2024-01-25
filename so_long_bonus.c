/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:02:08 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/25 21:53:25 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_utils/so_long_bonus.h"

void	fill_map(t_info *info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x] && info->map[y][x] != '\n')
		{
			put_img(info, FLOOR, x * 32, y * 32);
			if (info->map[y][x] == '1' && (y > 0
				&& y < info->hight) && (x > 0 && x < info->width))
				put_img(info, "textures/wall.xpm", x * 32, y * 32);
			if (info->map[y][x] == 'C')
				put_img(info, "textures/coins.xpm", x * 32, y * 32);
			if (info->map[y][x] == 'E')
				put_img(info, CLOSED, x * 32, y * 32);
			x++;
		}
		y++;
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

	fill_map(info);
	put_img(info, PLYR_TO_BOTTOM, info->plyr.px * 32, info->plyr.py * 32);
	fill_top_bottom(info);
	fill_right_left(info);
	hight = ((info->hight * 32) - 32);
	width = ((info->width * 32) - 32);
	put_img(info, TOP_LEFT, 0, 0);
	put_img(info, TOP_RIGHT, width, 0);
	put_img(info, BOTTOM_LEFT, 0, hight);
	put_img(info, BOTTOM_RIGHT, width, hight);
	show_clicks(info);
}

int	main(int ac, char *av[])
{
	t_info	info;

	if (ac != 2)
	{
		ft_printf("Error :\nInvalid args\nExample : %s /path/to/map", av[0]);
		exit(-1);
	}
	_init(&info);
	info.map_path = av[1];
	name_checker(&info);
	info.map = copy_map(&info);
	get_map_data(&info);
	map_checker(&info);
	info.mons.path = copy_map(&info);
	launch_window(&info, av[0]);
	map_drawer(&info);
	mlx_hook(info.window, 2, 0, click_manager, &info);
	mlx_hook(info.window, 17, 0, destroy, &info);
	mlx_loop_hook(info.mlx_ptr, coin_flipper, &info);
	mlx_loop(info.mlx_ptr);
}
