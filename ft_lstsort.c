/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:13:53 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/18 17:42:30 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	compare(long f(const void *, const void *), void *a, void *b,
	const char reverse)
{
	if (!reverse)
		return (f(a, b));
	else
		return (-f(a, b));
}

t_list		**ft_lstsort(t_list **lst, long f(const void *, const void *),
	const char reverse)
{
	t_list	*sorted_list;
	t_list	*i;
	t_list	*next;
	t_list	*j;

	sorted_list = NULL;
	i = *lst;
	while (i)
	{
		next = i->next;
		if (sorted_list == NULL ||
			compare(f, sorted_list->content, i->content, reverse) >= 0)
			ft_lstadd(&sorted_list, i);
		else
		{
			j = sorted_list;
			while (j->next && compare(f, j->content, i->content, reverse) < 0)
				j = j->next;
			i->next = j->next;
			j->next = i;
		}
		i = next;
	}
	*lst = sorted_list;
	return (lst);
}
