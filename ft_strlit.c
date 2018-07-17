/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:37:51 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/17 11:52:04 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	replace(char c)
{
	if (c == 'n')
		return ('\n');
	if (c == 'b')
		return ('\b');
	if (c == '0')
		return (0);
	if (c == 't')
		return ('\t');
	if (c == 'a')
		return ('\a');
	if (c == 'r')
		return ('\r');
	if (c == 'v')
		return ('\v');
	if (c == 'e')
		return ('\e');
	return (c);
}

char		*ft_strlit(char *str, size_t n)
{
	char *ret;
	char *dup;

	ret = ft_strnew(n + 1);
	dup = ret;
	while (*str && n--)
	{
		if (*str == '\\')
			*dup++ = replace(*++str);
		else
			*dup++ = *str;
		str++;
	}
	*dup = 0;
	return (ret);
}
