/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:38:55 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/01 11:31:40 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*ret;
	const size_t	len = ft_strlen(s1) + 1;

	if (!(ret = malloc(len)))
		return (NULL);
	return (ft_memcpy(ret, s1, len));
}
