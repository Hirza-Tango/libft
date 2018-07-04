/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:13:53 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/04 14:53:18 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_lstsort(t_list **lst, int f(const void *, const void *),
	const char reverse)
{
	t_list	*i;
	t_list	*j;
	t_list	*smallest;

	i = *lst;
	if (!lst || !*lst)
		return (NULL);
	while (i->next)
	{
		smallest = i;
		j = i->next;
		while (j)
		{
			if ((f(j->content, i->content) < 0 && !reverse) ||
				(f(i->content, j->content) < 0 && reverse))
				smallest = j;
			j = j->next;
		}
		if (smallest != i)
			ft_lstswap(i, smallest);
		i = i->next;
	}
	return (lst);
}
