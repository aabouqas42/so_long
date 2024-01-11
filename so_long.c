/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:02:08 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/11 16:32:06 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		void	*mlx_ptr;
		void	*window;
		win_t	win;

		name_checker(av[1]);
		map_checker(av[1]);
		mlx_ptr = mlx_init();
		win = get_win_info(av[1]);
		window = mlx_new_window(mlx_ptr, win.width * 50 , win.hight * 100, "SO_LONG");
		mlx_loop(mlx_ptr);
	}
}