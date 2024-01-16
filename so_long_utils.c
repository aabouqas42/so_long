/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:22:01 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/16 22:54:17 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	show_message(char *message, int ret)
{
	ft_printf(message);
	exit(ret);
}

void	get_win_info(info_t *info)
{
	char	**map;

	map = info->map;
	info->hight = 0;
	info->width = ft_strlen(map[0]);
	while (map[info->hight])
		info->hight++;
}
int	open_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		show_message("cannot open file !\n", -1);
	return (fd);
}

void	get_map_data(info_t *info)
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
			info->player.py = ((c == 'P') * i) + info->player.py;
			info->player.px = ((c == 'P') * j) + info->player.px;
			info->player.dy = ((c == 'E') * i) + info->player.dy;
			info->player.dx = ((c == 'E') * j) + info->player.dx;
			info->mons.x = ((c == 'M') * j) + info->mons.x;
			info->mons.y = ((c == 'M') * i) + info->mons.y;
			info->coins += (c == 'C');
			j++;
		}
		i++;
	}
	info->hight = i;
	info->width = ft_strlen((const char *)info->map[0]);
}
