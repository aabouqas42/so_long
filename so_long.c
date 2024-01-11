/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:02:08 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/11 22:41:18 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drawer(void *mlx_pointer, void *window, void *image, int x, int y)
{
	mlx_put_image_to_window(mlx_pointer, window, image, x, y);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		win_t	win;
		void	*image;
		int		wimg;
		int		himg;

		wimg = 0;
		himg = 0;
		name_checker(av[1]);
		map_checker(av[1]);
		get_win_info(av[1], &win);
		win.mlx_ptr = mlx_init();
		win.window = mlx_new_window(win.mlx_ptr, win.width * 20 , win.hight * 50, "SO_LONG");
		image = mlx_xpm_file_to_image(win.mlx_ptr, "textures/floor.xpm", &wimg, &himg);
		int	hghit = 0;
		while (hghit < win.hight * 52)
		{
			int width = 0;
			while (width < win.width * 82)
			{
				mlx_put_image_to_window(win.mlx_ptr, win.window, image, width, hghit);
				width += 32;
			}
			mlx_put_image_to_window(win.mlx_ptr, win.window, image, 0, hghit);
			hghit += 32;
		}
		mlx_hook(win.window, 2, 0, program_closer, &win);
		mlx_hook(win.window, 17, 0, destroy, &win);
		mlx_loop(win.mlx_ptr);
	}
}