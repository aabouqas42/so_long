/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:22:01 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/21 00:42:46 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_message(t_info *info, char *message, int ret)
{
	ft_printf(message);
	mem_free(info->map);
	mem_free(info->mons.path);
	if (info->mlx_ptr && info->window)
		mlx_destroy_window(info->mlx_ptr, info->window);
	exit(ret);
}

void	get_win_info(t_info *info)
{
	char	**map;

	map = info->map;
	info->hight = 0;
	info->width = ft_strlen(map[0]);
	while (map[info->hight])
		info->hight++;
}

int	open_file(t_info *info)
{
	int	fd;

	fd = open(info->map_path, O_RDONLY);
	if (fd == -1)
		show_message(info, "cannot open file !\n", -1);
	return (fd);
}

void	get_map_data(t_info *info)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			c = info->map[i][j];
			info->plyr.py = ((c == 'P') * i) + info->plyr.py;
			info->plyr.px = ((c == 'P') * j) + info->plyr.px;
			info->plyr.dy = ((c == 'E') * i) + info->plyr.dy;
			info->plyr.dx = ((c == 'E') * j) + info->plyr.dx;
			info->coins += (c == 'C');
			j++;
		}
		i++;
	}
	info->mons.y = info->plyr.py;
	info->mons.x = info->plyr.px;
	info->hight = i;
	info->width = ft_strlen((const char *)info->map[0]);
}

void	_init(t_info *info)
{
	info->map = copy_map(info);
	info->mons.path = copy_map(info);
	info->mlx_ptr = 0;
	info->window = 0;
	info->speed = 5000;
	info->hight_img = 0;
	info->width_img = 0;
	info->coins = 0;
	info->valid = 0;
	info->counter = 0;
}
