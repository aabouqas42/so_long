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
		show_msg(info, "Congratulation You won :)\n", 0);
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
		{
			info->plyr.score++;
			info->map[info->plyr.py - 1][info->plyr.px] = '0';
			if (info->plyr.score == info->coins)
				put_img(info, OPNED, info->plyr.dx * 32, info->plyr.dy * 32);
		}
		anim_to_top(info, PLYR_TO_TOP, &info->plyr.px, &info->plyr.py);
		info->counter++;
		ft_printf("%d\n", info->counter);
	}
}

void	to_down(t_info *info)
{
	char	c;

	c = info->map[info->plyr.py + 1][info->plyr.px];
	if (c == 'E' && info->plyr.score == info->coins)
		show_msg(info, "Congratulation You won :)\n", 0);
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
		{
			info->plyr.score++;
			info->map[info->plyr.py + 1][info->plyr.px] = '0';
			if (info->plyr.score == info->coins)
				put_img(info, OPNED, info->plyr.dx * 32, info->plyr.dy * 32);
		}
		anim_to_bottom(info, PLYR_TO_BOTTOM, &info->plyr.px, &info->plyr.py);
		info->counter++;
		ft_printf("%d\n", info->counter);
	}
}

void	to_left(t_info *info)
{
	char	c;

	c = info->map[info->plyr.py][info->plyr.px - 1];
	if (c == 'E' && info->plyr.score == info->coins)
		show_msg(info, "Congratulation You won :)\n", 0);
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
		{
			info->plyr.score++;
			info->map[info->plyr.py][info->plyr.px - 1] = '0';
			if (info->plyr.score == info->coins)
				put_img(info, OPNED, info->plyr.dx * 32, info->plyr.dy * 32);
		}
		anim_to_left(info, PLYR_TO_LEFT, &info->plyr.px, &info->plyr.py);
		info->counter++;
		ft_printf("%d\n", info->counter);
	}
}

void	to_right(t_info *info)
{
	char	c;

	c = info->map[info->plyr.py][info->plyr.px + 1];
	if (c == 'E' && info->plyr.score == info->coins)
		show_msg(info, "Congratulation You won :)\n", 0);
	if (c == '0' || c == 'C' || c == 'P')
	{
		if (c == 'C')
		{
			info->plyr.score++;
			info->map[info->plyr.py][info->plyr.px + 1] = '0';
			if (info->plyr.score == info->coins)
				put_img(info, OPNED, info->plyr.dx * 32, info->plyr.dy * 32);
		}
		anim_to_right(info, PLYR_TO_RIGHT, &info->plyr.px, &info->plyr.py);
		info->counter++;
		ft_printf("%d\n", info->counter);
	}
}
