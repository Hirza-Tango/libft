/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:23:15 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/27 16:16:55 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*current;

	if (!(current = *alst))
	{
		*alst = new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
}
