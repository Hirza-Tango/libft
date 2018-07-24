/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:25:48 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/24 14:42:38 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse(t_list *curr, t_list *prev, t_list **head)
{
	t_list *next;

	if (!curr->next)
	{
		*head = curr;
		curr->next = prev;
		return ;
	}
	next = curr->next;
	curr->next = prev;
	reverse(next, curr, head);
}

void		ft_lstrev(t_list **lst)
{
	if (!lst)
		return ;
	reverse(*lst, NULL, lst);
}
