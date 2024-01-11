/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:56:46 by aabouqas          #+#    #+#             */
/*   Updated: 2023/11/11 16:33:53 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_count(char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_strndup(char *str, size_t end)
{
	char	*ptr;
	size_t	i;

	if (!str)
		return (0);
	ptr = malloc (end + 1);
	if (!ptr)
	{
		free (ptr);
		return (0);
	}
	i = 0;
	while (str[i] && i < end)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**fill(char **split, char *str, size_t words, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < words)
	{
		while (*str && *str == c)
			str++;
		j = 0;
		while (str[j] && str[j] != c)
			j++;
		split[i] = ft_strndup(str, j);
		if (!split[i])
		{
			while (i--)
				free (split[i]);
			free(split);
			return (0);
		}
		str += j;
		i++;
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**splitted;
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	words = word_count(str, c);
	splitted = malloc ((words + 1) * sizeof(char *));
	if (!splitted)
		return (0);
	return (fill(splitted, str, words, c));
}
