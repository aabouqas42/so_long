/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:15:59 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/14 00:34:32 by aabouqas         ###   ########.fr       */
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
	ft_printf("to top :: X > %d : Y > %d\n", mlx_data->_player.x, mlx_data->_player.y);
	if (map[i - 1][j] == 'E' && mlx_data->_player.score == mlx_data->coins)
		show_message("You win :)\n", 0);
	if (map[i - 1][j] == '0' || map[i - 1][j] == 'C' || map[i - 1][j] == 'P')
	{
		if (map[i - 1][j] == 'C')
			mlx_data->_player.score++;
		mlx_data->_player.y--;
		put_img(mlx_data, "textures/floor.xpm", x, y);
		put_img(mlx_data, "textures/floor.xpm", x, y - 32);
		put_img(mlx_data, "textures/hero.xpm", x, y - 32);
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
	ft_printf("to down :: X > %d : Y > %d\n", mlx_data->_player.x, mlx_data->_player.y);
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C' || map[i + 1][j] == 'P')
	{
		if (map[i + 1][j] == 'C')
			mlx_data->_player.score++;
		mlx_data->_player.y++;
		put_img(mlx_data, "textures/floor.xpm", x, y);
		put_img(mlx_data, "textures/floor.xpm", x, y + 32);
		put_img(mlx_data, "textures/hero.xpm", x, y + 32);
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
	ft_printf("to left :: X > %d : Y > %d\n", mlx_data->_player.x, mlx_data->_player.y);
	if (map[i][j - 1] == '0' || map[i][j - 1] == 'C' || map[i][j - 1] == 'P')
	{
		if (map[i][j - 1] == 'C')
			mlx_data->_player.score++;
		mlx_data->_player.x--;
		put_img(mlx_data, "textures/floor.xpm", x, y);
		put_img(mlx_data, "textures/floor.xpm", x - 32, y);
		put_img(mlx_data, "textures/hero.xpm", x - 32, y);
	}
}

void	to_right(win_t *mlx_data)
{
	char	**map;
	int		i;
	int		j;
	int		x;
	int		y;

	map = mlx_data->map;
	x = mlx_data->_player.x * 32;
	y = mlx_data->_player.y * 32;
	i = mlx_data->_player.y;
	j = mlx_data->_player.x;
	ft_printf("to right :: X > %d : Y > %d\n", mlx_data->_player.x, mlx_data->_player.y);
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C' || map[i][j + 1] == 'P')
	{
		if (map[i][j + 1] == 'C')
			mlx_data->_player.score++;
		mlx_data->_player.x++;
		put_img(mlx_data, "textures/floor.xpm", x, y);
		put_img(mlx_data, "textures/floor.xpm", x + 32, y);
		put_img(mlx_data, "textures/hero.xpm", x + 32, y);
	}
}
