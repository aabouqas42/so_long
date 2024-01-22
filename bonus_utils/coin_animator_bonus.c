/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_animator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 23:52:46 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/21 23:54:10 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_frame(int time)
{
	char	*frame;

	if (time == 0)
		frame = "textures/coins/c1.xpm";
	if (time == 1)
		frame  = "textures/coins/c2.xpm";
	if (time == 2)
		frame = "textures/coins/c3.xpm";
	if (time == 3)
		frame = "textures/coins/c4.xpm";
	if (time == 4)
		frame = "textures/coins/c5.xpm";
	return (frame);
}

void	coin_animator(t_info *info, int time)
{
	int	i;
	int	j;

	i = 1;
	while (info->map[i])
	{
		j = 1;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'C' && j  < (ft_strlen(info->map[i]) - 1))
			{
				put_img(info, FLOOR, j * 32, i * 32);
				put_img(info, get_frame(time), j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
}

int	coin_flipper(t_info *info)
{
	static int		time = 0;
	static size_t	n = 0;

	if (n == 800)
	{
		coin_animator(info, time);
		time++;
		if (time == 5)
			time = 0;
		n = 0;
	}
	n++;
	return (0);
}
