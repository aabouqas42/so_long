/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:22:01 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/11 16:26:29 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	show_error(char *message)
{
	ft_printf(message);
	exit(-1);
}

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
win_t	get_win_info(char *map_path)
{
	win_t	window;
	char	**mp;

	mp = copy_map(map_path);
	window.hight = 0;
	window.width = ft_strlen(mp[0]);
	while (mp[window.hight])
		window.hight++;
	mem_free(mp);
	return (window);
}