/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:02:08 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/12 13:32:57 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	generate_image(char *textuer_path, win_t *mlx_data)
{
	mlx_data->image = mlx_xpm_file_to_image(mlx_data->mlx_ptr, textuer_path, &mlx_data->width_img, &mlx_data->hight_img);
}

void	map_drawer(win_t *mlx_data)
{
	int		hight;
	int		width;
	int		w;
	int		h;
	char	**map;
	char	*wall;

	hight = 0;
	width = 0;
	w = 0;
	h = 0;
	wall = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "textures/wall.xpm", &mlx_data->width_img, &mlx_data->hight_img);
	map = copy_map(mlx_data->map_path);
	while (map[hight])
	{
		width = 0;
		w = 0;
		while (map[hight][width])
		{
			if (map[hight][width] != '1')
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->window, mlx_data->image, w, h);
			else if (map[hight][width] == '1')
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->window, wall, w, h);
			width++;
			w += 32;
		}
		hight++;
		h += 32;
	}
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
		win.mlx_ptr = mlx_init();
		win.window = mlx_new_window(win.mlx_ptr, win.width * 32, win.hight * 32, "SO_LONG");
		win.image = mlx_xpm_file_to_image(win.mlx_ptr, "textures/floor.xpm", &win.width_img, &win.hight_img);
		// int	height = 0;
		// while (height < win.hight * 32)
		// {
		// 	int width = 0;
		// 	while (width < win.width * 32)
		// 	{
		// 		mlx_put_image_to_window(win.mlx_ptr, win.window, win.image, width, height);
		// 		width+=32;
		// 	}
		// 	mlx_put_image_to_window(win.mlx_ptr, win.window, win.image, 0, height);
		// 	height+=32;
		// }

		map_drawer(&win);
		//mlx_loop_hook(win.mlx_ptr, render_next_frame, &win);
		mlx_hook(win.window, 2, 0, program_closer, &win);
		mlx_hook(win.window, 17, 0, destroy, &win);
		mlx_loop(win.mlx_ptr);
	}
}
