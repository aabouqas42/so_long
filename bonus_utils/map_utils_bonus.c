/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:26:36 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/25 15:24:46 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mem_free(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free(map);
}

size_t	map_size(int fd)
{
	size_t	len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	if ((!line || !*line) || line[0] == '\n')
	{
		close (fd);
		ft_printf("Error :\nInvalid map :(\n");
		exit(-1);
	}
	while (line)
	{
		len++;
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

char	**copy_map(t_info *info)
{
	int		fd;
	char	**map;
	size_t	size;
	size_t	i;

	fd = open_file(info);
	size = map_size(fd) + 1;
	map = malloc (size * sizeof(char *));
	if (map == NULL)
	{
		close (fd);
		show_msg(info, "Error :\nunexpected error :(\n", -1);
	}
	fd = open_file(info);
	i = 0;
	while (i < size)
	{
		map[i] = get_next_line(fd);
		if (map[i] && map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
	close (fd);
	return (map);
}

void	check_objects(t_info *info, char **map)
{
	size_t	x;
	size_t	y;
	int		p;
	int		c;
	int		e;

	p = 0;
	c = 0;
	e = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			p += (map[y][x] == 'P');
			c += (map[y][x] == 'C');
			e += (map[y][x] == 'E');
			x++;
		}
		y++;
	}
	if ((p > 1 || p == 0) || (e > 1 || e == 0) || c == 0)
		show_msg(info, "Error :\nMap requires 1P, 1E, & C >= 1. :(\n", -1);
}
void	check_invalid_chars(t_info *info)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (ft_strchr("01ECP", info->map[y][x]) == 0)
				show_msg(info, "Error :\nAllowed chars: \"01ECP\" :(\n", -1);
			x++;
		}
		y++;
	}
}
