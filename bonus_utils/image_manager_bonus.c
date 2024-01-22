/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:56:51 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/21 22:32:22 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*get_img(char *textuer_path, t_info *info)
{
	void	*image;

	image = mlx_xpm_file_to_image(info->mlx_ptr, textuer_path,
			&info->width_img, &info->hight_img);
	if (image == NULL)
		show_message(info, "Error :\nwrong texture path :(\n", -1);
	return (image);
}

void	put_img(t_info *info, void *textuer_path, int x, int y)
{
	void	*image;

	image = get_img(textuer_path, info);
	mlx_put_image_to_window(info->mlx_ptr, info->window, image, x, y);
	mlx_destroy_image(info->mlx_ptr, image);
}
