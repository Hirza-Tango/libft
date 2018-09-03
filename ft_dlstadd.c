/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 11:09:45 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/03 13:17:45 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_dlstadd(t_d_list **alst, t_d_list *new)
{
	if (!alst)
		return ;
	if (*alst)
		(*alst)->prev = new;
	new->next = *alst;
	*alst = new;
}
