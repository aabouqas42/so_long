/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:59:47 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/25 23:49:24 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_info *info)
{
	if (info->map)
		mem_free(info->map);
	if (info->mlx_ptr && info->window)
		mlx_destroy_window(info->mlx_ptr, info->window);
	exit (0);
}

int	click_manager(int key, t_info *info)
{
	if (key == 53)
		destroy(info);
	if ((key == 126) || (key == 13))
		to_top(info);
	if ((key == 125) || key == 1)
		to_down(info);
	if ((key == 124) || (key == 2))
		to_right(info);
	if ((key == 123) || (key == 0))
		to_left(info);
	return (0);
}
