/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:36:20 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/11 15:47:27 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unsetenv(const char *name, char **env)
{
	char			**dup;
	char			**new;
	char			**newdup;
	size_t			size;

	if (!name || !*name || ft_strchr(name, '='))
		return (-1);
	size = 0;
	dup = env;
	while (*dup)
	{
		if (ft_strncmp(name, *dup, ft_strlen(name)))
			size++;
		dup++;
	}
	if (!(new = (char **)malloc(sizeof(char *) * (size + 1))))
		return (-2);
	newdup = new;
	dup = env;
	while (*dup)
		*newdup++ = *dup++;
	*newdup = NULL;
	free(env);
	env = new;
	return (0);
}
