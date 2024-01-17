/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:18:27 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/17 20:02:58 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	name_checker(char *map_name)
{
	int	i;

	i = 0;
	while (map_name[i] && map_name[i] != '.')
		i++;
	if (map_name[i] == '\0' || ft_strcmp(&map_name[i], ".ber") != 0)
		show_message("invalide file\n", -1);
}


void	check_rows(info_t info)
{
	int	i;

	i = 0;
	while (info.map[i])
	{
		if (ft_strlen(info.map[i]) != info.width)
			show_message("invalide map :(\n", -1);
		i++;
	}
	i = 0;
	while (i < info.hight)
	{
		if (info.map[i][0] != '1' || info.map[i][info.width - 1] != '1')
			show_message("Kkkkkinvalide map :(\n", -1);
		i++;
	}
	i = 0;
	while (i < info.width)
	{

		if (info.map[0][i] != '1' || info.map[info.hight - 1][i] != '1')
			show_message("invalide map :(\n", -1);
		i++;
	}
}

void	map_checker(info_t info)
{
	static int	player;
	static int	coins;
	static int	exit;
	char	c;
	size_t	i;
	size_t	j;

	i = 0;
	check_rows(info);
	while (info.map[i])
	{
		j = 0;
		while (info.map[i][j])
		{
			c = info.map[i][j];
			player += (c == 'P');
			coins +=  (c == 'C');
			exit += (c == 'E');
			j++;
		}
		i++;
	}
	if ((player > 1 || player == 0) || (exit == 0 || exit > 1) || coins == 0)
		show_message("invalide map :(\n", -1);
}
void	check(info_t *info, char **map, int start_x, int start_y)
{
	char	c;
	if (start_x < 0 || start_x >= info->width || start_y < 0 || start_y >= info->hight)
		return ;
	if (map[start_y][start_x] == '1' || map[start_y][start_x] == 'V')
		return ;
	c = info->map[start_y][start_x];
	if (c == 'C' || c == 'E')
		info->valid++;
	map[start_y][start_x] = 'V';
	check(info, map, start_x, start_y - 1);
	check(info, map, start_x, start_y + 1);
	check(info, map, start_x - 1, start_y);
	check(info, map, start_x + 1, start_y);
}

void	flood_fill(info_t *info)
{
	char	**map;

	map = copy_map(info->map_path);
	check (info, map, info->player.px, info->player.py);
	mem_free(map);
	if (info->valid != (info->coins + 1))
		show_message("invalide path :(\n", -1);
}
