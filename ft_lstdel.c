/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:24:06 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/04 13:25:02 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*curr;
	t_list	*next;

	if (!alst)
		return ;
	curr = *alst;
	while (curr)
	{
		next = curr->next;
		ft_lstdelone(&curr, del);
		curr = next;
	}
	*alst = NULL;
}
