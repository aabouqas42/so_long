/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:02:08 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/14 19:51:15 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(win_t *mlx_data, char **map, void *textures)
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
		j = 0;
		width = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			put_img(mlx_data, textures, width, hight);
			if (map[i][j] == '1' && (i > 0 && i < mlx_data->hight) && (j > 0 && j < mlx_data->width))
				put_img(mlx_data, "textures/wall.xpm", width, hight);
			if (map[i][j] == 'C')
				put_img(mlx_data, "textures/coins.xpm", width, hight);
			if (map[i][j] == 'E')
				put_img(mlx_data, "textures/door_closed.xpm", width, hight);
			(j++, width += 32);
		}
		i++;
		hight += 32;
	}
}
void	fill_top_bottom(win_t *mlx_data)
{
	int	width;
	int	hight;

	width = 0;
	hight = (mlx_data->hight * 32) - 32;
	while (width < (mlx_data->width * 32))
	{
		put_img(mlx_data, "textures/top_bottom.xpm", width, 0);
		put_img(mlx_data, "textures/top_bottom.xpm", width, hight);
		width += 32;
	}
}

void	fill_right_left(win_t *mlx_data)
{
	int	width;
	int	hight;

	width = (mlx_data->width * 32) - 32;
	hight = 32;
	while (hight < (mlx_data->hight * 32))
	{
		put_img(mlx_data, "textures/left.xpm", 0, hight);
		put_img(mlx_data, "textures/right.xpm", width, hight);
		hight += 32;
	}
	put_img(mlx_data, "textures/culomn_top.xpm", 0, 32);
	put_img(mlx_data, "textures/culomn_top.xpm", width, 32);
	put_img(mlx_data, "textures/culomn_bottom.xpm", 0, hight - 64);
	put_img(mlx_data, "textures/culomn_bottom.xpm", width, hight - 64);
}

void	 map_drawer(win_t *mlx_data)
{
	int		hight;
	int		width;

	hight = 0;
	width = 0;
	fill_map(mlx_data, mlx_data->map, "textures/floor.xpm");
	put_img(mlx_data, "textures/hero.xpm", mlx_data->_player.x * 32, mlx_data->_player.y * 32);
	fill_top_bottom(mlx_data);
	fill_right_left(mlx_data);
	hight = (mlx_data->hight * 32) - 32;
	width = (mlx_data->width * 32) - 32;
	put_img(mlx_data, "textures/top_left.xpm", 0, 0);
	put_img(mlx_data, "textures/top_right.xpm", width, 0);
	put_img(mlx_data, "textures/bottom_left.xpm", 0, hight);
	put_img(mlx_data, "textures/bottom_right.xpm", width, hight);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		win_t	win;

		win.hight_img = 0;
		win.width_img = 0;
		win.map_path = av[1];
		win.coins = 0;
		win.map = copy_map(win.map_path);
		name_checker(win.map_path);
		map_checker(win);
		get_win_info(&win);
		get_player_position(&win);
		get_coin_count(&win);
		win.mlx_ptr = mlx_init();
		win.window = mlx_new_window(win.mlx_ptr, win.width * 32, win.hight * 32, "SO_LONG");
		win.image = mlx_xpm_file_to_image(win.mlx_ptr, "textures/top.xpm", &win.width_img, &win.hight_img);
		map_drawer(&win);
		mlx_hook(win.window, 2, 0, click_manager, &win);
		mlx_hook(win.window, 17, 0, destroy, &win);
		mlx_loop(win.mlx_ptr);
	}
}
