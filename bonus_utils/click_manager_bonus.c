/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:59:47 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/23 22:36:13 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	destroy(t_info *info)
{
	if (info->map)
		mem_free(info->map);
	if (info->mons.path)
		mem_free(info->mons.path);
	if (info->mlx_ptr && info->window)
		mlx_destroy_window(info->mlx_ptr, info->window);
	exit (0);
}

void	show_clicks(t_info *info)
{
	char	*score;
	int		x_floor;
	int		x_scoore;
	int		i;

	x_floor = ((info->width / 2) * 32) - 64;
	x_scoore = ((info->width / 2) * 32);
	score = ft_itoa(info->counter);
	ft_printf("%d\n", info->counter);
	i = x_floor + 128;
	while (x_floor <= i)
	{
		put_img(info, "textures/bg_scoore.xpm", x_floor, 0);
		x_floor += 32;
	}
	mlx_string_put(info->mlx_ptr, info->window, x_scoore, 0, 0xffffff, score);
	free (score);
}

int	click_manager(int key, t_info *info)
{
	if (key == 53)
		destroy(info);
	if ((key >= 123 && key <= 126) || (key >= 0 && key <= 3) || (key == 13))
		mlx_loop_hook(info->mlx_ptr, _monster_mover, info);
	if ((key == 126) || (key == 13))
		to_top(info);
	if ((key == 125) || key == 1)
		to_down(info);
	if ((key == 124) || (key == 2))
		to_right(info);
	if ((key == 123) || (key == 0))
		to_left(info);
	return (0);
}
