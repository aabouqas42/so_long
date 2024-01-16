/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:56:51 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/16 12:51:37 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_img(char *textuer_path, info_t *info)
{
	void	*image;

	image = mlx_xpm_file_to_image(info->mlx_ptr, textuer_path,
			&info->width_img, &info->hight_img);
	return (image);
}

void	put_img(info_t *info, void *textuer_path, int x, int y)
{
	void	*image;

	image = get_img(textuer_path, info);
	mlx_put_image_to_window(info->mlx_ptr, info->window, image, x, y);
}
