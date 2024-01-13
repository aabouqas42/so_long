/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:02:08 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/13 06:01:36 by aabouqas         ###   ########.fr       */
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
			if (map[i][j] == '0')
				put_img(mlx_data, textures, width, hight);
			j++;
			width += 32;
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
		put_img(mlx_data, "textures/top.xpm", width, 0);
		put_img(mlx_data, "textures/bottom.xpm", width, hight);
		width += 32;
	}
}

void	fill_right_left(win_t *mlx_data)
{
	int	width;
	int	hight;

	width = (mlx_data->width * 32) - 32;
	hight = 0;
	while (hight < (mlx_data->hight * 32))
	{
		put_img(mlx_data, "textures/left.xpm", 0, hight);
		put_img(mlx_data, "textures/right.xpm", width, hight);
		hight += 32;
	}
}

void	map_drawer(win_t *mlx_data)
{
	int		hight;
	int		width;

	hight = 0;
	width = 0;
	fill_map(mlx_data, mlx_data->map, "textures/floor.xpm");
	fill_top_bottom(mlx_data);
	fill_right_left(mlx_data);
	hight = (mlx_data->hight * 32) - 32;
	width = (mlx_data->width * 32) - 32;
	put_img(mlx_data, "textures/top_left.xpm", 0, 0);
	put_img(mlx_data, "textures/top_right.xpm", width, 0);
	put_img(mlx_data, "textures/bottom_left.xpm", 0, hight);
	put_img(mlx_data, "textures/bottom_right.xpm", width, hight);
}

int	render_next_frame(win_t *mlx_data)
{
	int	i = 0;
	while (i < 500)
	{
		mlx_clear_window(mlx_data->mlx_ptr, mlx_data->window);
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_ptr, mlx_data->image, i, 0);
		i++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		win_t	win;

		win.hight_img = 0;
		win.width_img = 0;
		win.map_path = av[1];
		name_checker(av[1]);
		map_checker(av[1]);
		get_win_info(av[1], &win);
		win.map = copy_map(av[1]);
		win.mlx_ptr = mlx_init();
		win.window = mlx_new_window(win.mlx_ptr, win.width * 32, win.hight * 32, "SO_LONG");
		win.image = mlx_xpm_file_to_image(win.mlx_ptr, "textures/top.xpm", &win.width_img, &win.hight_img);
		map_drawer(&win);
		mlx_hook(win.window, 2, 0, click_manager, &win);
		mlx_hook(win.window, 17, 0, destroy, &win);
		mlx_loop(win.mlx_ptr);
	}
}
