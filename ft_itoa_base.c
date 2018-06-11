/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:21:24 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/11 14:01:06 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recurse_print(intmax_t value, int base, char *spot, const char f)
{
	if (value < 10 && value < base)
		*spot = value + '0';
	else if (value < base)
		*spot = value + f - 10;
	else
	{
		recurse_print(value / base, base, spot - 1, f);
		if (value % base < 10)
			*spot = value % base + '0';
		else
			*spot = value % base + f - 10;
	}
}

char		*ft_itoa_base(intmax_t value, int base)
{
	char		*result;
	int			length;
	intmax_t	dummy;
	const char	hex_start = base < 0 ? 'a' : 'A';

	base = base < 0 ? -base : base;
	length = 1;
	if (base == 10 && value < 0)
		length++;
	dummy = value;
	while (value /= base)
		length++;
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	if (base == 10 && dummy < 0)
	{
		dummy *= -1;
		result[0] = '-';
	}
	recurse_print(dummy, base, result + length - 1, hex_start);
	result[length] = '\0';
	return (result);
}
