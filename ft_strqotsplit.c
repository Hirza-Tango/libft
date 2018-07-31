/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strqotsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:59:44 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/31 16:20:17 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_quote(const char *str, int i)
{
	char *pos;

	i++;
	while ((pos = ft_strchr(str + i, '\"')))
		if (str[i - 1] != '\\')
			break ;
	if (!pos)
		return (0);
	return (pos - str);
}

static int	count_words(char const *str)
{
	int		i;
	int		last_was_split;
	int		count;

	last_was_split = 1;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			last_was_split = 1;
		else
		{
			if (last_was_split)
				count++;
			if (last_was_split && str[i] == '\"')
				if (!(i = find_quote(str, i)))
					return (0);
			last_was_split = 0;
		}
		i++;
	}
	return (count);
}

static void	fill_array(char **result, char const *str)
{
	int		current_word;
	int		i;
	char	*start;

	i = -1;
	current_word = 0;
	while (str[++i])
		if (str[i] == '\"')
		{
			start = (char *)str + i++ + 1;
			while (str[i] && (str[i] != '\"' || str[i - 1] == '\\'))
				i++;
			result[current_word] = ft_strlit(start, str + i - start);
			current_word++;
		}
		else if (!ft_isspace(str[i]))
		{
			start = (char *)str + i;
			while (!ft_isspace(str[i]) && str[i])
				i++;
			result[current_word] = ft_strndup(start, str + i-- - start);
			current_word++;
		}
	result[current_word] = 0;
}

char		**ft_strqotsplit(char const *str)
{
	char		**result;
	const int	count = count_words(str);

	if (!str || !count)
		return (NULL);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	fill_array(result, str);
	return (result);
}
