/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 11:05:13 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/28 11:07:18 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_dlstdelone(t_d_list **alst, void (*del)(void*, size_t))
{
	ft_lstdelone((t_list **)alst, del);
}