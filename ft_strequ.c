/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:55:16 by dslogrov          #+#    #+#             */
/*   Updated: 2018/05/24 14:16:04 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	char	*c1;
	char	*c2;

	if (!s1 || !s2)
		return (0);
	c1 = (char *)s1;
	c2 = (char *)s2;
	while (*c1 && *c2)
	{
		if (
			(ft_islower(*c1) && ft_isupper(*c2)) ||
			(ft_isupper(*c1) && ft_islower(*c2)))
		{
			if (*c1++ - 32 - *c2++)
				return (0);
		}
		else if (*c1++ - *c2++)
			return (0);
	}
	if (*c1 || *c2)
		return (0);
	return (1);
}
