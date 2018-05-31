/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:12:17 by dslogrov          #+#    #+#             */
/*   Updated: 2018/05/31 14:56:21 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*c1;
	char	*c2;

	if (!s1 || !s2)
		return (0);
	if (!n)
		return (1);
	c1 = (char *)s1;
	c2 = (char *)s2;
	while (*c1 && *c2 && n--)
		if (*c1++ - *c2++)
			return (0);
	if (n + 1)
		if (*c1 || *c2)
			return (0);
	return (1);
}
