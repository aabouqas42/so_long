/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:26:36 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/21 22:32:27 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	line = get_next_line(fd);
	if ((!line || !*line) || line[0] == '\n')
	{
		close (fd);
		ft_printf("Error :\nempty map really ??? -_-\n");
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

	size = map_size(open_file(info)) + 1;
	map = malloc (size * sizeof(char *));
	if (map == NULL)
		show_message(info, "Error !\n", -1);
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
