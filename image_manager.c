/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:56:51 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/14 15:44:34 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_img(char *textuer_path, win_t *mlx_data)
{
	void	*image;

	image = mlx_xpm_file_to_image(mlx_data->mlx_ptr, textuer_path,
			&mlx_data->width_img, &mlx_data->hight_img);
	return (image);
}

void	put_img(win_t *mlx_data, void *textuer_path, int x, int y)
{
	void	*image;

	image = get_img(textuer_path, mlx_data);
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->window, image, x, y);
}
