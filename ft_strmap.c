/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:16:00 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/01 11:44:44 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	size_t	i;

	if (!f || !s)
		return (NULL);
	if (!(result = malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = (*f)(s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
