/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:38:30 by aabouqas          #+#    #+#             */
/*   Updated: 2023/11/13 10:27:46 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ws(char c)
{
	return ((c >= 9 && c <= 13) || (c == 32));
}

int	ft_atoi(const char *str)
{
	int		s;
	long	r;

	s = 1;
	r = 0;
	while (ws(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		r = r * 10 + (*str - 48);
		if((s == 1 && r < 0) || (s == -1 && (r * (-1)) > 0))
		{
			if(s == 1)
				return -1;
			return 0;
		}
		str++;
	}
	return (r * s);
}

