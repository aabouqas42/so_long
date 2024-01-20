/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:48:53 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/20 18:24:36 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_the_line_bonus(char *line, char **rem_ltrs)
{
	char	*new_line;
	int		len;
	int		i;

	len = 0;
	if (!line || !*line)
		return (free (line), free (*rem_ltrs), *rem_ltrs = NULL, NULL);
	if (!found_newline_bonus(line))
		return (line);
	while (line[len] && line[len] != '\n')
		len++;
	len++;
	new_line = malloc (len + 1);
	if (!new_line)
		return (free (line), free (*rem_ltrs), *rem_ltrs = NULL, NULL);
	i = 0;
	while (line[i] && i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (free (line), new_line);
}

static void	*_free(int fd, char **rem_ltrs)
{
	if (fd >= 0 && fd < OPEN_MAX)
	{
		if (rem_ltrs[fd])
		{
			free (rem_ltrs[fd]);
			rem_ltrs[fd] = NULL;
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*rem[OPEN_MAX];
	char		*buffer;
	char		*line;
	int			readed;

	readed = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || (read (fd, 0, 0) < 0))
		return (_free(fd, rem), NULL);
	buffer = malloc ((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (_free(fd, rem));
	line = app_end_bonus(rem[fd], line);
	while (!found_newline_bonus(line) && readed)
	{
		readed = read (fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free(buffer), free (line), _free(fd, rem));
		buffer[readed] = '\0';
		line = app_end_bonus(line, buffer);
	}
	rem[fd] = get_remaining_letters_bonus(line);
	free (buffer);
	return (get_the_line_bonus(line, &rem[fd]));
}
