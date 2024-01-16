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
		put_img(info, FLOOR, (info->player.px * 32), (info->player.py * 32));
		put_img(info, FLOOR, (info->player.px * 32), ((info->player.py * 32) - 32));
		put_img(info, HERO, (info->player.px * 32), ((info->player.py * 32) - 32));
		info->player.py--;
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
		put_img(info, FLOOR, (info->player.px * 32), (info->player.py * 32));
		put_img(info, FLOOR, (info->player.px * 32), ((info->player.py * 32) + 32));
		put_img(info, HERO, (info->player.px * 32), ((info->player.py * 32) + 32));
		info->player.py++;
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
		put_img(info, FLOOR, (info->player.px * 32), (info->player.py * 32));
		put_img(info, FLOOR,( (info->player.px * 32) - 32), (info->player.py * 32));
		put_img(info, HERO, ((info->player.px * 32) - 32), (info->player.py * 32));
		info->player.px--;
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
		put_img(info, FLOOR, (info->player.px * 32), (info->player.py * 32));
		put_img(info, FLOOR, ((info->player.px * 32) + 32), (info->player.py * 32));
		put_img(info, HERO, ((info->player.px * 32) + 32), (info->player.py * 32));
		info->player.px++;
	}
}
