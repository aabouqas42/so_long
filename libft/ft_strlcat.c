/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:09:00 by aabouqas          #+#    #+#             */
/*   Updated: 2023/11/13 12:12:00 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	if (!dest && srclen && !dstsize)
		return (0);
	destlen = ft_strlen(dest);
	if (!dstsize)
		return (srclen);
	if (dstsize <= destlen)
		return (dstsize + srclen);
	i = destlen;
	while (*src && i < (dstsize - 1))
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = 0;
	return (destlen + srclen);
}
