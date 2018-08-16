/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:38:44 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/16 15:33:40 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstrm(t_list **list, size_t index, void (*del)(void *, size_t))
{
	size_t	i;
	t_list	*dup;
	t_list	*next;

	if (!list || !*list)
		return ;
	if (!index)
	{
		ft_lstdelone(list, del);
		return ;
	}
	dup = *list;
	i = 0;
	while (dup->next)
	{
		if (i++ == index - 1)
		{
			next = dup->next->next;
			ft_lstdelone(&(dup->next), del);
			dup->next = next;
			return ;
		}
		dup = dup->next;
	}
}
