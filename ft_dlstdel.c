/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 11:07:52 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/04 13:48:06 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_dlstdel(t_d_list **alst, void (*del)(void*, size_t))
{
	t_d_list	*curr;
	t_d_list	*next;

	if (!alst)
		return ;
	curr = *alst;
	while (curr)
	{
		next = curr->next;
		ft_dlstdelone(&curr, del);
		curr = next;
	}
	*alst = NULL;
}
