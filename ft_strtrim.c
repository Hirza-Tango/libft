/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:07:32 by dslogrov          #+#    #+#             */
/*   Updated: 2018/05/23 15:35:50 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*start;
	char	*end;
	char	*ret;
	char	*new;

	if (!s)
		return (NULL);
	start = (char *)s;
	while (*start == ' ' || *start == '\n' || *start == '\t')
		start++;
	end = (char *)s + ft_strlen(s) - 1;
	while ((*end == ' ' || *end == '\n' || *end == '\t') && end >= start)
		end--;
	ret = malloc(end - start + 2);
	if (!ret)
		return (NULL);
	new = ret;
	while (start <= end)
		*new++ = *start++;
	*new = 0;
	return (ret);
}
