/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programe_closer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:59:47 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/11 19:00:27 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(void *ptr)
{
	(void)ptr;
	exit (0);
}

int	program_closer(int key_code)
{
	ft_printf("%d\n", key_code);
	if (key_code == 53)
		exit(0);
	return (0);
}
