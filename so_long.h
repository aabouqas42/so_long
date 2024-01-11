/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:36:09 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/11 16:05:00 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SO_LONG_H_
# define _SO_LONG_H_

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

typedef struct win_s {
	int width;
	int hight;
} win_t;

void	show_error(char *message);
win_t	get_win_info(char *map_path);
void	mem_free(char **map);

void	name_checker(char *map_name);
void	map_checker(char *map_path);
size_t	map_size(int fd);
char	**copy_map(char *map_path);



#endif