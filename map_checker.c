/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:18:27 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/11 22:22:50 by aabouqas         ###   ########.fr       */
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
		show_error("invalide file\n");
}

char	**copy_map(char *map_path)
{
	int		fd;
	char	**map;
	size_t	size;
	size_t	i;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		show_error("cannot open file !\n");
	size = map_size(fd) + 1;
	map = malloc (size * sizeof(char *));
	if (map == NULL)
		exit (-1);
	fd = open(map_path, O_RDONLY);
	i = 0;
	while (i < size)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close (fd);
	return (map);
}

void	check_rows(char *row)
{
	int	i;

	i = 0;
	while (row[i] && row[i] != '\n')
	{
		if (row[i] != '1')
			show_error("invalide map :(\n");
		i++;
	}
}

void	check_items(char *line, size_t size, int end)
{
	static int	po;
	static int	co;
	static int	ex;
	size_t		i;
	char		c;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		c = line[i];
		if (c == 'P')
			po++;
		if (c == 'C')
			co++;
		if (c == 'E')
			ex++;
		if ((c != '0') && (c != '1') && (c != 'P') && (c != 'E') && (c != 'C'))
			show_error("invalide map :(\n");
		i++;
	}
	if (end)
		if ((po > 1 || po == 0) || (ex > 1 || ex == 0) || co == 0)
			show_error("invalide map :(\n");
	if (i != size)
		show_error("invalide map :(\n");
}

void	map_checker(char *map_path)
{
	size_t	i;
	size_t	size;
	char	**map;

	map = copy_map(map_path);
	size = ft_strlen((const char *)map[0]) - 1;
	i = 0;
	while (map[i])
	{
		check_items(map[i], size, (map[i + 1] == NULL));
		if (i == 0 || map[i + 1] == NULL)
			check_rows(map[i]);
		if ((map[i][0] != '1') || (map[i][size - 1] != '1'))
			show_error("invalide map :(\n");
		i++;
	}
}
