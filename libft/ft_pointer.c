/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:50:24 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/10 13:53:59 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	baselen(unsigned long num)
{
	int	len;

	len = 0;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static int	ft_helper(char *str, unsigned long p, char *base, int len)
{
	if (ft_putstr ("0x") == -1)
	{
		free(str);
		return (-1);
	}
	while (p)
	{
		str[len] = base[p % 16];
		p /= 16;
		len--;
	}
	if (ft_putstr(str) == -1)
	{
		free (str);
		return (-1);
	}
	len = ft_strlen(str);
	free (str);
	return (len + 2);
}

int	ft_pointer(unsigned long p)
{
	char	*str;
	char	*base;
	int		len;

	if (p == 0)
		return (ft_putstr("0x0"));
	base = "0123456789abcdef";
	len = baselen(p);
	str = malloc (len + 1);
	if (!str)
		return (-1);
	str[len] = '\0';
	return (ft_helper(str, p, base, (len - 1)));
}
