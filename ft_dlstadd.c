/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 11:09:45 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/28 11:11:51 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_dlstadd(t_d_list **alst, t_d_list *new)
{
	(*alst)->prev = new;
	new->next = *alst;
	*alst = new;
}
