/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:27:13 by dslogrov          #+#    #+#             */
/*   Updated: 2018/05/24 13:44:58 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (src > dst)
	{
		d = dst;
		s = (char *)src;
		while (n--)
			*d++ = *s++;
	}
	else if (dst > src)
	{
		d = dst + n;
		s = (char *)src + n;
		while (n--)
			*--d = *--s;
	}
	return (dst);
}
