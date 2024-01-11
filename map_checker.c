/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:18:27 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/11 16:24:16 by aabouqas         ###   ########.fr       */
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
	size = map_size(fd);
	map = malloc (size * sizeof(char *));
	if (map == NULL)
		exit (-1);
	fd = open(map_path, O_RDONLY);
	i = 0;
	while (i < size)
	{
		map[i] = ft_strdup(get_next_line(fd));
		if (map[i] == NULL)
			while (i--)
				free (map[i]);
		i++;
	}
	close (fd);
	return (map[i] = 0, map);
}

int	check_rows(char *row)
{
	int	i;

	i = 0;
	while (row[i] && row[i] != '\n')
	{
		if (row[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_items(char *line, size_t size, int end)
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
			return (-1);
		i++;
	}
	if (end)
		if ((po > 1 || po == 0) || (ex > 1 || ex == 0) || co == 0)
			return (-1);
	return (i != size);
}

void	map_checker(char *map_path)
{
	size_t	i;
	size_t	size;
	char	**map;

	i = 0;
	map = copy_map(map_path);
	size = ft_strlen((const char *)map[0]) - 1;
	while (map[i])
	{
		if (check_items(map[i], size, (map[i + 1] == NULL)) == -1)
			(/*mem_free(map),*/ show_error("invalide map :(\n"));
		if (i == 0 || map[i + 1] == NULL)
			if (check_rows(map[i]) == -1)
				(/*mem_free(map),*/ show_error("invalide map :(\n"));
		if ((map[i][0] != '1') || (map[i][size - 1] != '1'))
			(/*mem_free(map),*/ show_error("invalide map :(\n"));
		i++;
	}
	//mem_free(map);
}
