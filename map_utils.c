/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:26:36 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/18 00:39:29 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mem_free(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		free (map[i++]);
	free(map);
}

size_t	map_size(int fd)
{
	size_t	len;
	char	*line;

	len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free (line);
		len++;
	}
	close(fd);
	return (len);
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
