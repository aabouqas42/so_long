/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:31:41 by aabouqas          #+#    #+#             */
/*   Updated: 2024/01/25 23:11:20 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_unsigned(unsigned int num)
{
	char	*str;
	int		len;

	if (num == 0)
		return (ft_putchar_fd('0', 1), 1);
	len = ft_numlen(num);
	str = malloc (len + 1);
	if (!str)
		return (-1);
	str[len] = '\0';
	len--;
	while (num)
	{
		str[len] = (num % 10) + 48;
		num /= 10;
		len--;
	}
	if (ft_putstr(str) == -1)
	{
		free (str);
		return (-1);
	}
	len = ft_strlen(str);
	free (str);
	return (len);
}
