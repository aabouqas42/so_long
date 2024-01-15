/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:22:01 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/15 19:33:25 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	show_message(char *message, int ret)
{
	ft_printf(message);
	exit(ret);
}

void	get_win_info(win_t *mlx_data)
{
	char	**map;

	map = mlx_data->map;
	mlx_data->hight = 0;
	mlx_data->width = ft_strlen(map[0]);
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

void	get_map_data(win_t *mlx_data)
{
	int		i;
	int		j;
	char	**map;
	char	c;

	map = mlx_data->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c == 'P')
				(mlx_data->_player.x = j, mlx_data->_player.y = i);
			if (c == 'E')
				(mlx_data->_player.door_x = j, mlx_data->_player.door_y = i);
			if (c == 'C')
				mlx_data->coins++;
			j++;
		}
		i++;
	}
	mlx_data->hight = i;
	mlx_data->width = ft_strlen((const char *)map[0]);
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
