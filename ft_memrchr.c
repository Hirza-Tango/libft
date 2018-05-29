/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 10:18:39 by dslogrov          #+#    #+#             */
/*   Updated: 2018/05/20 11:41:58 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	size_t i;

	i = n;
	while (i--)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
	}
	return (NULL);
}
