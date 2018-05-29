/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:40:44 by dslogrov          #+#    #+#             */
/*   Updated: 2018/05/24 13:52:12 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int		i;
	int		last_was_split;
	int		count;

	last_was_split = 1;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			last_was_split = 1;
		else
		{
			if (last_was_split)
				count++;
			last_was_split = 0;
		}
		i++;
	}
	return (count);
}

static void	fill_array(char **result, char const *str, char c)
{
	int		current_word;
	int		i;
	char	*start;

	i = 0;
	current_word = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			start = (char *)str + i;
			while (str[i] != c && str[i])
				i++;
			result[current_word] = ft_strndup(start, str + i - start);
			current_word++;
		}
	}
	result[current_word] = 0;
}

char		**ft_strsplit(char const *str, char c)
{
	char	**result;

	if (!str)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!result)
		return (NULL);
	fill_array(result, str, c);
	return (result);
}
