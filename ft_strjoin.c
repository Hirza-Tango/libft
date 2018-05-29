/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 21:33:50 by dslogrov          #+#    #+#             */
/*   Updated: 2018/05/24 13:46:36 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *result;
	char *iter;
	char *c1;
	char *c2;

	c1 = (char *)s1;
	c2 = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) + (ft_strlen(s1) + ft_strlen(s2) + 1));
	iter = result;
	if (!result)
		return (NULL);
	while (*c1)
		*(iter++) = *(c1++);
	while (*c2)
		*(iter++) = *(c2++);
	*iter = 0;
	return (result);
}
