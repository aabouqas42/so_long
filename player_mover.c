/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:15:59 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/13 06:13:53 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_top(win_t *mlx_data)
{
	char	**map;

	map = mlx_data->map;
	get_player_position(mlx_data);
	if (map[(mlx_data->_player.y) - 1][mlx_data->_player.x] == '0')
	{
		mlx_data->map[mlx_data->_player.y][mlx_data->_player.x] = '0';
		mlx_data->map[(mlx_data->_player.y) - 1][mlx_data->_player.x] = 'P';
		mlx_clear_window(mlx_data->mlx_ptr, mlx_data->window);
		put_img(mlx_data, )
	}
}

void	to_down(win_t *mlx_data)
{
	char	**map;

	map = mlx_data->map;
	get_player_position(mlx_data);
	if (map[mlx_data->_player.y + 1][mlx_data->_player.x] == '0')
	{
		mlx_data->map[mlx_data->_player.y][mlx_data->_player.x] = '0';
		mlx_data->map[(mlx_data->_player.y) + 1][mlx_data->_player.x] = 'P';
		mlx_clear_window(mlx_data->mlx_ptr, mlx_data->window);
		map_drawer(mlx_data);
	}
}
void	to_left(win_t *mlx_data)
{
	char	**map;

	map = mlx_data->map;
	get_player_position(mlx_data);
	if (map[mlx_data->_player.y][mlx_data->_player.x - 1] == '0')
	{
		mlx_data->map[mlx_data->_player.y][mlx_data->_player.x] = '0';
		mlx_data->map[(mlx_data->_player.y)][mlx_data->_player.x - 1] = 'P';
		mlx_clear_window(mlx_data->mlx_ptr, mlx_data->window);
		map_drawer(mlx_data);
	}
}

void	to_right(win_t *mlx_data)
{
	char	**map;

	map = mlx_data->map;
	get_player_position(mlx_data);
	if (map[mlx_data->_player.y][mlx_data->_player.x + 1] == '0')
	{
		mlx_data->map[mlx_data->_player.y][mlx_data->_player.x] = '0';
		mlx_data->map[(mlx_data->_player.y)][mlx_data->_player.x + 1] = 'P';
		mlx_clear_window(mlx_data->mlx_ptr, mlx_data->window);
		map_drawer(mlx_data);
	}
}
