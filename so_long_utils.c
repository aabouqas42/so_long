/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:22:01 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/19 15:12:41 by aabouqas         ###   ########.fr       */
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
			info->coins += (c == 'C');
			j++;
		}
		i++;
	}
	info->monster.y = info->player.py;
	info->monster.x = info->player.px;
	info->hight = i;
	info->width = ft_strlen((const char *)info->map[0]);
}

void	prtmap(char **map)
{
	int i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}
