/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:27:13 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/01 12:07:51 by dslogrov         ###   ########.fr       */
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
		ft_memcpy(dst, src, len);
	return (dst);
}
