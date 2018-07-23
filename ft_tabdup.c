/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:04:51 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/23 15:00:24 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	char	**dup;
	char	**ret;
	char	**retdup;
	size_t	len;

	dup = tab;
	len = 0;
	while (*(dup++))
		len++;
	ret = malloc(sizeof(char *) * (len + 1));
	retdup = ret;
	dup = tab;
	while (*dup)
		*(retdup++) = ft_strdup(*(dup++));
	*retdup = NULL;
	return (ret);
}
