/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:15:59 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/14 00:34: by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_top(win_t *mlx_data)
{
	char	**map;
	int		x;
	int		y;
	int		i;
	int		j;

	map = mlx_data->map;
	x = mlx_data->_player.x * 32;
	y = mlx_data->_player.y * 32;
	i = mlx_data->_player.y;
	j = mlx_data->_player.x;
	if (mlx_data->_player.score == mlx_data->coins)
	{
		put_img(mlx_data, DOOR_OPNED, mlx_data->_player.door_x, mlx_data->_player.door_y);
		if (map[i - 1][j] == 'E')
			show_message("You won :)\n", 0);
	}
	if (map[i - 1][j] == '0' || map[i - 1][j] == 'C' || map[i - 1][j] == 'P')
	{
		if (map[i - 1][j] == 'C')
			(mlx_data->_player.score++, map[i - 1][j] = '0');
		mlx_data->_player.y--;
		put_img(mlx_data, FLOOR, x, y);
		put_img(mlx_data, FLOOR, x, y - 32);
		put_img(mlx_data, HERO, x, y - 32);
	}
}

void	to_down(win_t *mlx_data)
{
	char	**map;
	int		x;
	int		y;
	int		i;
	int		j;

	map = mlx_data->map;
	x = mlx_data->_player.x * 32;
	y = mlx_data->_player.y * 32;
	i = mlx_data->_player.y;
	j = mlx_data->_player.x;
	if ((map[i + 1][j] == 'E' ) && (mlx_data->_player.score == mlx_data->coins))
		show_message("You won :)\n", 0);
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C' || map[i + 1][j] == 'P')
	{
		if (map[i + 1][j] == 'C')
		{
			mlx_data->_player.score++;
			map[i + 1][j] = '0';
		}
		mlx_data->_player.y++;
		put_img(mlx_data, FLOOR, x, y);
		put_img(mlx_data, FLOOR, x, y + 32);
		put_img(mlx_data, HERO, x, y + 32);
	}
}
void	to_left(win_t *mlx_data)
{
	char	**map;
	int		x;
	int		y;
	int		i;
	int		j;

	map = mlx_data->map;
	x = mlx_data->_player.x * 32;
	y = mlx_data->_player.y * 32;
	i = mlx_data->_player.y;
	j = mlx_data->_player.x;
	if ((map[i][j - 1] == 'E' ) && (mlx_data->_player.score == mlx_data->coins))
		show_message("You win :)\n", 0);
	if (map[i][j - 1] == '0' || map[i][j - 1] == 'C' || map[i][j - 1] == 'P')
	{
		if (map[i][j - 1] == 'C')
		{
			mlx_data->_player.score++;
			map[i][j - 1] = '0';
		}
		mlx_data->_player.x--;
		put_img(mlx_data, FLOOR, x, y);
		put_img(mlx_data, FLOOR, x - 32, y);
		put_img(mlx_data, HERO, x - 32, y);
	}
}

void	to_right(win_t *mlx_data)
{
	char	c;
	int		i;
	int		j;
	int		x;
	int		y;

	x = mlx_data->_player.x * 32;
	y = mlx_data->_player.y * 32;
	i = mlx_data->_player.y;
	j = mlx_data->_player.x;
	c = mlx_data->map[i][j + 1];
	if (mlx_data->_player.score == mlx_data->coins)
	{
		put_img(mlx_data, DOOR_OPNED,500, 500);
		if (c == 'E')
			show_message("You win :)\n", 0);
	}
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
			(mlx_data->_player.score++, mlx_data->map[i][j + 1] = '0');
		mlx_data->_player.x++;
		put_img(mlx_data, FLOOR, x, y);
		put_img(mlx_data, FLOOR, x + 32, y);
		put_img(mlx_data, HERO, x + 32, y);
	}
}
