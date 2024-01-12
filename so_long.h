/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:36:09 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/13 00:22:29 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SO_LONG_H_
# define _SO_LONG_H_

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

typedef struct win_s {
	void	*mlx_ptr;
	void	*window;
	char	*map_path;
	int		width;
	int		hight;
	void	*image;
	int		width_img;
	int		hight_img;
} win_t;

void	show_error(char *message);
void	get_win_info(char *map_path, win_t *win);
void	mem_free(char **map);
int		program_closer(int key_code);
int		destroy(void *ptr);
void	name_checker(char *map_name);
void	map_checker(char *map_path);
size_t	map_size(int fd);
char	**copy_map(char *map_path);
int		open_file(char *file_path);
void	*get_img(char *textuer_path, win_t *mlx_data);
void	put_img(win_t *mlx_data, void *textuer_path, int x, int y);
void	fill_map(win_t *mlx_data, char **map, void *textures);


#endif