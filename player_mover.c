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

void	to_top(info_t *info)
{
	char	c;

	c = info->map[info->player.py - 1][info->player.px];
	if (c == 'E' && info->player.score == info->coins)
		show_message("You won :)\n", 0);
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
		{
			info->player.score++;
			info->map[info->player.py - 1][info->player.px] = '0';
			if (info->player.score == info->coins)
				put_img(info, DOOR_OPNED, info->player.dx * 32, info->player.dy * 32);
		}
		animate_to_top(info, PLYR_TLUP, &info->player.px, &info->player.py);
	}
}

void	to_down(info_t *info)
{
	char	c;

	c = info->map[info->player.py + 1][info->player.px];
	if (c == 'E' && info->player.score == info->coins)
		show_message("You won :)\n", 0);
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
		{
			info->player.score++;
			info->map[info->player.py + 1][info->player.px] = '0';
			if (info->player.score == info->coins)
				put_img(info, DOOR_OPNED, (info->player.dx * 32), (info->player.dy * 32));
		}
		animate_to_down(info, PLYR_TLDW, &info->player.px, &info->player.py);
	}
}
void	to_left(info_t *info)
{
	char	c;

	c = info->map[info->player.py][info->player.px - 1];
	if (c == 'E' && info->player.score == info->coins)
		show_message("You win :)\n", 0);
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
		{
			info->player.score++;
			info->map[info->player.py][info->player.px - 1] = '0';
			if (info->player.score == info->coins)
				put_img(info, DOOR_OPNED, (info->player.dx * 32), (info->player.dy * 32));
		}
		animate_to_left(info, PLYR_TLFT, &info->player.px, &info->player.py);
	}
}

void	to_right(info_t *info)
{
	char	c;

	c = info->map[info->player.py][info->player.px + 1];
	if (c == 'E' && info->player.score == info->coins)
		show_message("You win :)\n", 0);
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
		{
			info->player.score++;
			info->map[info->player.py][info->player.px + 1] = '0';
			if (info->player.score == info->coins)
				put_img(info, DOOR_OPNED, info->player.dx * 32, info->player.dy * 32);
		}
		animate_to_right(info, PLYR_TRGT, &info->player.px, &info->player.py);
	}
}

int	_monster(info_t *info)
{
	static size_t	i;
	static int		direction = 1;
	char			c;

	if (info->player.px == info->monster.x && info->player.py == info->monster.y)
		show_message("You lose hhhhhhh :)\n", -1);
	if (i == 2000)
	{
		if (direction == 1)
		{
			animate_to_right(info, MONSTER_TO_RIGHT, &info->monster.x, &info->monster.y);
			c = info->map[info->monster.y][info->monster.x + 1];
			if (c == '1' || c == 'C' || c == 'E')
				direction = 0;
		} else if (direction == 0) {
			animate_to_left(info, MONSTER_TO_LEFT, &info->monster.x, &info->monster.y);
			c = info->map[info->monster.y][info->monster.x - 1];
			if (c == '1' || c == 'C' || c == 'E')
				direction = 1;
		}
		i = 0;
	}
	i++;
	return (0);
}
