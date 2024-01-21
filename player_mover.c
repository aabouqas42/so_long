/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plyr_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:15:59 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/14 00:34: by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_top(t_info *info)
{
	char	c;

	c = info->map[info->plyr.py - 1][info->plyr.px];
	if (c == 'E' && info->plyr.score == info->coins)
		show_message(info, "You won :)\n", 0);
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
		{
			info->plyr.score++;
			if (info->speed > 1200)
				info->speed -= 100;
			info->map[info->plyr.py - 1][info->plyr.px] = '0';
			if (info->plyr.score == info->coins)
				put_img(info, OPNED, info->plyr.dx * 32, info->plyr.dy * 32);
		}
		anim_to_top(info, PLYR_TO_TOP, &info->plyr.px, &info->plyr.py);
		info->mons.path[info->plyr.py][info->plyr.px] = 'P';
		info->counter++;
	}
}

void	to_down(t_info *info)
{
	char	c;

	c = info->map[info->plyr.py + 1][info->plyr.px];
	if (c == 'E' && info->plyr.score == info->coins)
		show_message(info, "You won :)\n", 0);
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
		{
			info->plyr.score++;
			if (info->speed > 1200)
				info->speed -= 100;
			info->map[info->plyr.py + 1][info->plyr.px] = '0';
			if (info->plyr.score == info->coins)
				put_img(info, OPNED, info->plyr.dx * 32, info->plyr.dy * 32);
		}
		anim_to_bottom(info, PLYR_TO_BOTTOM, &info->plyr.px, &info->plyr.py);
		info->mons.path[info->plyr.py][info->plyr.px] = 'P';
		info->counter++;
	}
}

void	to_left(t_info *info)
{
	char	c;

	c = info->map[info->plyr.py][info->plyr.px - 1];
	if (c == 'E' && info->plyr.score == info->coins)
		show_message(info, "You win :)\n", 0);
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
		{
			info->plyr.score++;
			if (info->speed > 1200)
				info->speed -= 100;
			info->map[info->plyr.py][info->plyr.px - 1] = '0';
			if (info->plyr.score == info->coins)
				put_img(info, OPNED, info->plyr.dx * 32, info->plyr.dy * 32);
		}
		anim_to_left(info, PLYR_TO_LEFT, &info->plyr.px, &info->plyr.py);
		info->mons.path[info->plyr.py][info->plyr.px] = 'P';
		info->counter++;
	}
}

void	to_right(t_info *info)
{
	char	c;

	c = info->map[info->plyr.py][info->plyr.px + 1];
	if (c == 'E' && info->plyr.score == info->coins)
		show_message(info, "You win :)\n", 0);
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
		{
			info->plyr.score++;
			if (info->speed > 1200)
				info->speed -= 100;
			info->map[info->plyr.py][info->plyr.px + 1] = '0';
			if (info->plyr.score == info->coins)
				put_img(info, OPNED, info->plyr.dx * 32, info->plyr.dy * 32);
		}
		anim_to_right(info, PLYR_TO_RIGHT, &info->plyr.px, &info->plyr.py);
		info->mons.path[info->plyr.py][info->plyr.px] = 'P';
		info->counter++;
	}
}

void	monster_animator(t_info *info)
{
	if (info->mons.path[info->mons.y][info->mons.x + 1] == 'P')
		anim_to_right(info, MONSTER_TO_RIGHT, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y][info->mons.x - 1] == 'P')
		anim_to_left(info, MONSTER_TO_LEFT, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y + 1][info->mons.x] == 'P')
		anim_to_bottom(info, MONSTER_TO_BOTTOM, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y - 1][info->mons.x] == 'P')
		anim_to_top(info, MONSTER_TO_TOP, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y + 1][info->mons.x] == '0'
		&& info->plyr.py > info->mons.y)
		anim_to_bottom(info, MONSTER_TO_BOTTOM, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y - 1][info->mons.x] == '0'
		&& info->plyr.py < info->mons.y)
		anim_to_top(info, MONSTER_TO_TOP, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y][info->mons.x + 1] == '0'
		&& info->plyr.px > info->mons.x)
		anim_to_right(info, MONSTER_TO_RIGHT, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y][info->mons.x - 1] == '0'
		&& info->plyr.px < info->mons.x)
		anim_to_left(info, MONSTER_TO_LEFT, &info->mons.x, &info->mons.y);
}
