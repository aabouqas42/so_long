/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:28:06 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/23 16:34:53 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlen;
	int		same;

	if (!haystack && !len)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	needlen = ft_strlen(needle);
	i = 0;
	while (haystack[i] && len)
	{
		if (haystack[i] == *needle)
		{
			same = ft_strncmp(&haystack[i], needle, needlen);
			if (len >= needlen && same == 0)
				return ((char *)&haystack[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}
