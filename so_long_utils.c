/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:22:01 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/14 15:46:40 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	show_message(char *message, int ret)
{
	ft_printf(message);
	exit(ret);
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
void	get_win_info(win_t *mlx_data)
{
	char	**map;

	map = mlx_data->map;
	mlx_data->hight = 0;
	mlx_data->width = ft_strlen(map[0]) - 1;
	while (map[mlx_data->hight])
		mlx_data->hight++;
}
int	open_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		show_message("cannot open file !\n", -1);
	return (fd);
}

void	get_player_position(win_t *mlx_data)
{
	int		i;
	int		j;
	char	**map;

	map = mlx_data->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				mlx_data->_player.x = j;
				mlx_data->_player.y = i;
				return;
			}
			j++;
		}
		i++;
	}
}
void	get_coin_count(win_t *mlx_data)
{
	char	**map;
	int		i;
	int		j;

	map = mlx_data->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				mlx_data->coins++;
			j++;
		}
		i++;
	}
}
