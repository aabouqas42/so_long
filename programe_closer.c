/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programe_closer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:59:47 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/18 04:28:25 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(void *ptr)
{
	(void)ptr;
	exit (0);
}

int	click_manager(int key_code, info_t *info)
{
	if (key_code == 53)
		exit(0);
	if ((key_code >= 123 && key_code <= 126) || (key_code >= 0 && key_code <= 3) || (key_code == 13))
	{
		mlx_loop_hook(info->mlx_ptr, _monster, info);
		//follow_me(info);
	}
	if ((key_code == 126) || (key_code == 13))
		to_top(info);
	if ((key_code == 125) || key_code == 1)
		to_down(info);
	if  ((key_code == 124) || (key_code == 2))
		to_right(info);
	if ((key_code == 123) || (key_code == 0))
		to_left(info);
	put_img(info, TOP,( info->width * 32) / 2, 0);
	mlx_string_put(info->mlx_ptr, info->window, (info->width * 32) / 2, 0, 0xffffff, ft_itoa(info->counter));
	ft_printf("%d\n", info->counter);
	//ft_printf("%d\n", key_code);
	return (0);
}

