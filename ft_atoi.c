/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:56:12 by dslogrov          #+#    #+#             */
/*   Updated: 2018/05/23 17:59:22 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	char	*byte;
	int		result;
	int		sign;

	byte = (char *)str;
	while (ft_isspace(*byte))
		byte++;
	sign = 1;
	if (*byte == '-')
	{
		sign = -1;
		byte++;
	}
	else if (*byte == '+')
		byte++;
	result = 0;
	while (*byte >= '0' && *byte <= '9')
	{
		result = result * 10 + (*byte - '0');
		byte++;
	}
	return (sign * result);
}
