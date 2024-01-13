/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programe_closer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:59:47 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/13 06:07:44 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(void *ptr)
{
	(void)ptr;
	exit (0);
}

int	click_manager(int key_code, win_t *mlx_data)
{
	ft_printf("%d\n", key_code);
	if (key_code == 53)
		exit(0);
	if (key_code == 126)
		to_top(mlx_data);
	if (key_code == 125)
		to_down(mlx_data);
	if  (key_code == 124)
		to_right(mlx_data);
	if (key_code == 123)
		to_left(mlx_data);
	return (0);
}
