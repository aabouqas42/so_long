/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:28:41 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/10 14:49:24 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_bonus(char *str)
{
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*app_end_bonus(char *str1, char *str2)
{
	char	*str;
	int		len;
	int		i;

	if (!str1 && !str2)
		return (NULL);
	len = ft_strlen_bonus(str1) + ft_strlen_bonus(str2);
	i = 0;
	str = malloc (len + 1);
	if (!str)
		return (free (str1), NULL);
	if (str1)
	{
		while (str1[i])
		{
			str[i] = str1[i];
			i++;
		}
	}
	if (str2)
		while (*str2)
			str[i++] = *(str2++);
	str[i] = '\0';
	return (free (str1), str);
}

int	found_newline_bonus(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_remaining_letters_bonus(char *str)
{
	char	*rem_ltrs;
	int		len;
	int		i;

	if (!found_newline_bonus(str) || !str)
		return (NULL);
	while (*str && *str != '\n')
		str++;
	str++;
	if (!*str)
		return (NULL);
	len = ft_strlen_bonus(str);
	rem_ltrs = malloc (len + 1);
	if (!rem_ltrs)
		return (NULL);
	i = 0;
	while (str[i])
	{
		rem_ltrs[i] = str[i];
		i++;
	}
	rem_ltrs[i] = '\0';
	return (rem_ltrs);
}
