/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:18:27 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/15 16:10:18 by aabouqas         ###   ########.fr       */
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

char	**copy_map(char *map_path)
{
	int		fd;
	char	**map;
	size_t	size;
	size_t	i;

	size = map_size(open_file(map_path)) + 1;
	map = malloc (size * sizeof(char *));
	if (map == NULL)
		exit (-1);
	fd = open_file(map_path);
	i = 0;
	while (i < size)
	{
		map[i] = get_next_line(fd);
		if (map[i] && map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i])-1] = '\0';
		i++;
	}
	return (close (fd), map);
}

void	check_rows(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
			show_message("invalide map :(\n", -1);
		i++;
	}
}

void	check_items(char *line, size_t size, int end)
{
	static int	player;
	static int	coins;
	static int	exit;
	size_t		i;
	char		c;

	i = 0;
	while (line[i])
	{
		c = line[i];
		player += (c == 'P');
		coins +=  (c == 'C');
		exit += (c == 'E');
		if (ft_strchr("01PEC", c) == 0)
			show_message("invalide map\n", -1);
		i++;
	}
	if (end)
		if ((player > 1 || player == 0) || (exit > 1 || exit == 0) || coins == 0)
			show_message("invalide map :(\n", -1);
	if (i != size)
		show_message("invalide map :(\n", -1);
}

void	map_checker(win_t mlx_data)
{
	size_t	i;
	size_t	size;
	char	**map;

	map = mlx_data.map;
	size = ft_strlen((const char *)map[0]);
	i = 0;
	while (map[i])
	{
		check_items(map[i], size, (map[i + 1] == NULL));
		if (i == 0 || map[i + 1] == NULL)
			check_rows(map[i]);
		if ((map[i][0] != '1') || (map[i][size - 1] != '1'))
			show_message("invalide map :(\n", -1);
		i++;
	}
}
