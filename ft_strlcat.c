/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 09:22:06 by dslogrov          #+#    #+#             */
/*   Updated: 2018/05/24 13:46:51 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	const size_t	size = ft_strlen(dst);

	if (dstsize < size)
		return (dstsize + ft_strlen(src));
	i = 0;
	while ((i < dstsize - size - 1) && src[i])
	{
		dst[i + size] = src[i];
		i++;
	}
	while (i < dstsize - size)
		dst[i++ + size] = 0;
	return (size + ft_strlen(src));
}
