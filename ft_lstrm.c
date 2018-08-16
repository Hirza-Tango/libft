/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:38:44 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/16 16:03:04 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	rm(t_list *before, void (*del)(void *, size_t))
{
	t_list	*next;

	next = before->next->next;
	ft_lstdelone(&(before->next), del);
	before->next = next;
}

void		ft_lstrm(t_list **list, size_t index, void (*del)(void *, size_t))
{
	size_t	i;
	t_list	*dup;
	t_list	*next;

	if (!list || !*list)
		return ;
	if (!index)
	{
		next = (*list)->next;
		ft_lstdelone(list, del);
		*list = next;
		return ;
	}
	dup = *list;
	i = 0;
	while (dup->next)
	{
		if (i++ == index - 1)
		{
			rm(dup, del);
			return ;
		}
		dup = dup->next;
	}
}
