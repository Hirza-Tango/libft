/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:29:14 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/18 12:42:57 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recurse_print(uintmax_t value, unsigned int base, char *spot, const char f)
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

char		*ft_utoa_base(uintmax_t value, int base)
{
	char		*result;
	int			length;
	uintmax_t	dummy;
	const char	hex_start = base < 0 ? 'a' : 'A';

	base = base < 0 ? -base : base;
	length = 1;
	dummy = value;
	while (value /= base)
		length++;
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	recurse_print(dummy, base, result + length - 1, hex_start);
	result[length] = '\0';
	return (result);
}
