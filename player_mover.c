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
				put_img(info, OD, info->plyr.dx * 32, info->plyr.dy * 32);
		}
		a_to_t(info, PLYR_TLUP, &info->plyr.px, &info->plyr.py);
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
				put_img(info, OD, (info->plyr.dx * 32), (info->plyr.dy * 32));
		}
		a_to_d(info, PLYR_TLDW, &info->plyr.px, &info->plyr.py);
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
				put_img(info, OD, (info->plyr.dx * 32), (info->plyr.dy * 32));
		}
		a_to_l(info, PLYR_TLFT, &info->plyr.px, &info->plyr.py);
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
				put_img(info, OD, info->plyr.dx * 32, info->plyr.dy * 32);
		}
		a_to_r(info, PLYR_TRGT, &info->plyr.px, &info->plyr.py);
		info->mons.path[info->plyr.py][info->plyr.px] = 'P';
		info->counter++;
	}
}

void	anim(t_info *info)
{
	if (info->mons.path[info->mons.y][info->mons.x + 1] == 'P')
		a_to_r(info, M_TO_R, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y][info->mons.x - 1] == 'P')
		a_to_l(info, M_TO_L, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y + 1][info->mons.x] == 'P')
		a_to_d(info, M_TO_B, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y - 1][info->mons.x] == 'P')
		a_to_t(info, M_TO_T, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y + 1][info->mons.x] == '0'
		&& info->plyr.py > info->mons.y)
		a_to_d(info, M_TO_B, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y - 1][info->mons.x] == '0'
		&& info->plyr.py < info->mons.y)
		a_to_t(info, M_TO_T, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y][info->mons.x + 1] == '0'
		&& info->plyr.px > info->mons.x)
		a_to_r(info, M_TO_R, &info->mons.x, &info->mons.y);
	else if (info->mons.path[info->mons.y][info->mons.x - 1] == '0'
		&& info->plyr.px < info->mons.x)
		a_to_l(info, M_TO_L, &info->mons.x, &info->mons.y);
}
