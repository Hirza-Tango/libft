/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:13:53 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/26 17:07:50 by dslogrov         ###   ########.fr       */
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
	while (i->next)
	{
		smallest = i;
		j = i->next;
		while (j)
			if ((f(j->content, i->content) < 0 && !reverse) ||
				(f(i->content, j->content) < 0 && reverse))
				smallest = j;
		if (smallest != i)
			ft_lstswap(i, smallest);
	}
	return (lst);
}
