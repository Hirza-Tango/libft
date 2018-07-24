/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:13:53 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/24 14:37:16 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		**ft_lstsort(t_list **lst, long (*f)(const void *, const void *))
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
		if (sorted_list == NULL || (f(sorted_list->content, i->content) >= 0L))
			ft_lstadd(&sorted_list, i);
		else
		{
			j = sorted_list;
			while (j->next && (f(j->content, i->content) < 0L))
				j = j->next;
			i->next = j->next;
			j->next = i;
		}
		i = next;
	}
	*lst = sorted_list;
	return (lst);
}
