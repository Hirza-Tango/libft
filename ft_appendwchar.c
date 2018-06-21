/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendwchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:02:44 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/21 12:58:27 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_appendwchar(wchar_t wc, char *str)
{
	const char *ret = str;

	str += ft_strlen(str);
	if (wc <= 0x7F)
		*str = (unsigned char)wc;
	else if (wc <= 0x7FF)
	{
		*str++ = 0xC0 | (wc >> 6 & 0x1F);
		*str++ = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0xFFFF)
	{
		*str++ = 0xE0 | (wc >> 12 & 0xF);
		*str++ = 0x80 | (wc >> 6 & 0x3F);
		*str++ = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0x10FFFF)
	{
		*str++ = 0xF0 | (wc >> 18 & 0x7);
		*str++ = 0x80 | (wc >> 12 & 0x3F);
		*str++ = 0x80 | (wc >> 6 & 0x3F);
		*str++ = 0x80 | (wc & 0x3F);
	}
	return ((char *)ret);
}
