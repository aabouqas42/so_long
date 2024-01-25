/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:22:01 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/25 14:59:50 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	show_msg(t_info *info, char *message, int ret)
{
	ft_printf(message);
	if (info->map)
		mem_free(info->map);
	if (info->mons.path)
		mem_free(info->mons.path);
	if (info->mlx_ptr && info->window)
		mlx_destroy_window(info->mlx_ptr, info->window);
	exit(ret);
}

int	open_file(t_info *info)
{
	int	fd;

	fd = open(info->map_path, O_RDONLY);
	if (fd == -1)
		show_msg(info, "Error :\nCannot open file :(\n", -1);
	return (fd);
}

void	get_map_data(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			info->plyr.py = ((info->map[i][j] == 'P') * i) + info->plyr.py;
			info->plyr.px = ((info->map[i][j] == 'P') * j) + info->plyr.px;
			info->plyr.dy = ((info->map[i][j] == 'E') * i) + info->plyr.dy;
			info->plyr.dx = ((info->map[i][j] == 'E') * j) + info->plyr.dx;
			info->coins += (info->map[i][j] == 'C');
			j++;
		}
		i++;
	}
	info->mons.y = info->plyr.py;
	info->mons.x = info->plyr.px;
	info->hight = i;
	info->width = ft_strlen((const char *)info->map[0]);
	info->win_w = info->width * 32;
	info->win_h = info->hight * 32;
}

void	_init(t_info *info)
{
	info->mlx_ptr = NULL;
	info->window = NULL;
	info->map = NULL;
	info->mons.path = NULL;
	info->speed = 2500;
	info->plyr.score = 0;
	info->plyr.py = 0;
	info->plyr.px = 0;
	info->plyr.dx = 0;
	info->plyr.dy = 0;
	info->hight_img = 0;
	info->width_img = 0;
	info->coins = 0;
	info->valid = 0;
	info->counter = 0;
}

void	launch_window(t_info *info, char *title)
{
	info->mlx_ptr = mlx_init();
	if (info->mlx_ptr == NULL)
		show_msg(info, "Error :\nUnexpected error :(\n", -1);
	info->window = mlx_new_window(
			info->mlx_ptr, info->win_w, info->win_h, title);
	if (info->window == NULL)
		show_msg(info, "Error :\nUnexpected error :(\n", -1);
}
