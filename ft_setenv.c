/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:53:24 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/11 15:21:27 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	tab_len(char **tab)
{
	char	**dup;
	size_t	len;

	dup = tab;
	len = 0;
	while (*(dup++))
		len++;
	return (len);
}

static int		rebuild(const char *name, const char *value, char ***env)
{
	char			**dup;
	char			**result;
	char			**newdup;

	ft_putendl("DEBUG: Rebuilding...");
	if (!(result = (char **)malloc(sizeof(char *) * (tab_len(*env) + 2))))
		return (-2);
	newdup = result;
	dup = *env;
	while (*dup)
		*newdup++ = *dup++;
	if (!(*dup = ft_strnew(ft_strlen(name) + ft_strlen(value) + 2)))
	{
		free(result);
		return (-2);
	}
	*dup = ft_strcat(ft_strcat(ft_strcat(*dup, name), "="), value);
	*newdup++ = *dup;
	*dup = NULL;
	*newdup = NULL;
	free(env);
	*env = result;
	return (0);
}

static int		try_replace(const char *name, const char *value, int ov,
	char **env)
{
	char			**dup;

	dup = env;
	while (*dup)
	{
		if (ft_strnequ(*dup, name,
			MAX((size_t)(ft_strchr(*dup, '=') - *dup), ft_strlen(name))))
		{
			if (ov)
			{
				free(*dup);
				if (!(*dup = ft_strnew(ft_strlen(name) + ft_strlen(value) + 2)))
					return (-2);
				*dup = ft_strcat(ft_strcat(ft_strcat(*dup, name), "="), value);
			}
			return (0);
		}
		dup++;
	}
	return (1);
}

int				ft_setenv(const char *name, const char *value, int overwrite,
	char **env)
{
	int				status;

	if (!name || !*name || ft_strchr(name, '='))
		return (-1);
	if (!(status = try_replace(name, value, overwrite, env)))
		return (0);
	else if (status == -2)
		return (-2);
	if (rebuild(name, value, &env) == -2)
		return (-2);
	return (0);
}
