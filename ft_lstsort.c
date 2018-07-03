/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:13:53 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/03 16:43:08 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_lstsort(t_list **lst, int f(const void *, const void *),
	const char reverse)
{
	t_list	**start;
	t_list	*dup;

	if (!lst || !*lst)
		return (lst);
	start = lst;
	dup = *lst;
	while (dup->next)
	{
		if((f(dup->content, dup->next->content) < 0 && !reverse) ||
			(f(dup->content, dup->next->content) > 0 && reverse))
		{
			ft_lstswap(dup, dup->next);
			dup = *start;
		}
		else
			dup = dup->next;
	}
	return (start);
}
