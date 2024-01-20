/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programe_closer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:59:47 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/20 20:51:47 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_info *info)
{
	mlx_destroy_window(info->mlx_ptr, info->window);
	mem_free(info->map);
	mem_free(info->mons.path);
	system("leaks so_long");
	exit (0);
}

int	click_manager(int key, t_info *info)
{
	char	*score;
	int		x;

	if (key == 53)
		destroy(info);
	if ((key >= 123 && key <= 126) || (key >= 0 && key <= 3) || (key == 13))
	{
		put_img(info, TOP, ((info->width * 32) / 2), 0);
		score = ft_itoa(info->counter);
		x = (info->width * 32) / 2;
		mlx_string_put(info->mlx_ptr, info->window, x, 0, 0xffffff, score);
		free (score);
		mlx_loop_hook(info->mlx_ptr, _monster_mover, info);
	}
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
