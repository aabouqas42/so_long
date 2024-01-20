/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:03:17 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/20 20:56:00 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	a_to_t(t_info *info, void *_char, int *x, int *y)
{
	char	c;

	c = info->map[*y - 1][*x];
	if (c == '0' || c == 'P')
	{
		put_img(info, FLOOR, (*x * 32), (*y * 32));
		put_img(info, FLOOR, (*x * 32), (*y * 32) - 32);
		put_img(info, _char, (*x * 32), (*y * 32) - 32);
		(*y)--;
	}
}

void	a_to_d(t_info *info, void *_char, int *x, int *y)
{
	char	c;

	c = info->map[*y + 1][*x];
	if (c == '0' || c == 'P')
	{
		put_img(info, FLOOR, (*x * 32), (*y * 32));
		put_img(info, FLOOR, (*x * 32), (*y * 32) + 32);
		put_img(info, _char, (*x * 32), (*y * 32) + 32);
		(*y)++;
	}
}

void	a_to_r(t_info *info, void *_char, int *x, int *y)
{
	char	c;

	c = info->map[*y][*x + 1];
	if (c == '0' || c == 'P')
	{
		put_img(info, FLOOR, (*x * 32), (*y * 32));
		put_img(info, FLOOR, (*x * 32) + 32, (*y * 32));
		put_img(info, _char, (*x * 32) + 32, (*y * 32));
		(*x)++;
	}
}

void	a_to_l(t_info *info, void *_char, int *x, int *y)
{
	char	c;

	c = info->map[*y][*x - 1];
	if (c == '0' || c == 'P')
	{
		put_img(info, FLOOR, (*x * 32), (*y * 32));
		put_img(info, FLOOR, (*x * 32) - 32, (*y * 32));
		put_img(info, _char, (*x * 32) - 32, (*y * 32));
		(*x)--;
	}
}

int	_monster_mover(t_info *info)
{
	static size_t	i = 0;

	if ((info->plyr.py == info->mons.y) && (info->plyr.px == info->mons.x))
		show_message(info, "Game Over :(\n", -1);
	if (i >= info->speed)
	{
		info->mons.path[info->mons.y][info->mons.x] = '0';
		anim(info);
		prtmap(info->mons.path);
		i = 0;
	}
	i++;
	return (0);
}
