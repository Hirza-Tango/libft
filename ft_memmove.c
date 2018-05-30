/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:27:13 by dslogrov          #+#    #+#             */
/*   Updated: 2018/05/30 10:27:17 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	if (src > dst)
	{
		d = dst;
		s = (char *)src;
		while (len--)
			*d++ = *s++;
	}
	else if (dst > src)
	{
		d = dst + len;
		s = (char *)src + len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}
