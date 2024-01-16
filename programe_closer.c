/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programe_closer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:59:47 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/16 12:52:02 by aabouqas         ###   ########.fr       */
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
	if (key_code == 126)
		to_top(info);
	if (key_code == 125)
		to_down(info);
	if  (key_code == 124)
		to_right(info);
	if (key_code == 123)
		to_left(info);
	return (0);
}
