/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:45:30 by dslogrov          #+#    #+#             */
/*   Updated: 2018/05/24 13:51:20 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*c1 = (unsigned char *)s1;
	const unsigned char	*c2 = (unsigned char *)s2;
	size_t				i;

	i = 0;
	while (c1[i] && c2[i] && i < n)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	if (i == n)
		return (0);
	if (c1[i])
		return (c1[i]);
	if (c2[i])
		return (-c2[i]);
	return (0);
}
