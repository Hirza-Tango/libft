/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:26:38 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/18 11:30:14 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

char	*ft_strmjoin(size_t count, ...)
{
	va_list	a;
	va_list	b;
	char	*ret;
	size_t	len;
	size_t	i;

	len = 0;
	va_start(a, count);
	va_copy(b, a);
	i = 0;
	while (i++ < count)
		len += ft_strlen(va_arg(a, const char *));
	va_end(a);
	ret = (char *)ft_strnew(len + 1);
	i = 0;
	while (i++ < count)
		ft_strlcat(ret, va_arg(b, const char *), len + 1);
	va_end(b);
	return (ret);
}
