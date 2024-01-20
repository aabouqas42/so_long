/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:18:27 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/20 20:51:26 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	name_checker(t_info *info)
{
	int	i;

	i = 0;
	while (info->map_path[i] && info->map_path[i] != '.')
		i++;
	if (info->map_path[i] == '\0' || ft_strcmp(&info->map_path[i], ".ber") != 0)
		show_message(info, "invalide file\n", -1);
}

void	check_rows(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		if (ft_strlen(info->map[i]) != info->width)
			show_message(info, "invalide map :(\n", -1);
		i++;
	}
	i = 0;
	while (i < info->hight)
	{
		if (info->map[i][0] != '1' || info->map[i][info->width - 1] != '1')
			show_message(info, "invalide map :(\n", -1);
		i++;
	}
	i = 0;
	while (i < info->width)
	{
		if (info->map[0][i] != '1' || info->map[info->hight - 1][i] != '1')
			show_message(info, "invalide map :(\n", -1);
		i++;
	}
}

void	map_checker(t_info *info)
{
	static int	player;
	static int	coins;
	static int	exit;
	size_t		i;
	size_t		j;

	i = 0;
	check_rows(info);
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			player += (info->map[i][j] == 'P');
			coins += (info->map[i][j] == 'C');
			exit += (info->map[i][j] == 'E');
			j++;
		}
		i++;
	}
	if ((player > 1 || player == 0) || (exit == 0 || exit > 1) || coins == 0)
		show_message(info, "invalide map :(\n", -1);
}

void	check(t_info *info, char **map, int start_x, int start_y)
{
	static int	checker = 0;

	if (start_x < 0 || start_y < 0
		|| start_x >= info->width || start_y >= info->hight)
		return ;
	if (map[start_y][start_x] == 'V')
		return ;
	if (map[start_y][start_x] == 'E' && checker == 0)
	{
		info->valid++;
		checker++;
		return ;
	}
	info->valid += (map[start_y][start_x] == 'C');
	map[start_y][start_x] = 'V';
	check(info, map, start_x, start_y + 1);
	check(info, map, start_x + 1, start_y);
	check(info, map, start_x, start_y - 1);
	check(info, map, start_x - 1, start_y);
}

void	flood_fill(t_info *info)
{
	char	**map;

	map = copy_map(info);
	check (info, map, info->plyr.px, info->plyr.py);
	mem_free(map);
	if (info->valid != (info->coins + 1))
		show_message(info, "invalide path :(\n", -1);
}
