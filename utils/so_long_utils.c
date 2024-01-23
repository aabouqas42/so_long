/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:22:01 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/23 21:38:32 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_msg(t_info *info, char *message, int ret)
{
	ft_printf(message);
	if (info->map)
		mem_free(info->map);
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
	info->win_w = 0;
	info->win_h = 0;
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
