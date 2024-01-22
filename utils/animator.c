/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:03:17 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/22 00:12:33 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_to_top(t_info *info, void *_char, int *x, int *y)
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

void	anim_to_bottom(t_info *info, void *_char, int *x, int *y)
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

void	anim_to_right(t_info *info, void *_char, int *x, int *y)
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

void	anim_to_left(t_info *info, void *_char, int *x, int *y)
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
