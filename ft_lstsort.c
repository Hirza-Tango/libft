/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:13:53 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/26 16:21:50 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/* This uses insertion sort. Other algorithms might be implemented later      */
/* ************************************************************************** */

t_list	**ft_lstsort(t_list **lst, void f(void *, void *))
{
	t_list	*i;
	t_list	*j;
	t_list	*smallest;

	i = *lst;
	while (i->next)
	{
		smallest = i;
		j = i->next;
		while (j)
			if (f(j->content, i->content) < 0)
				smallest = j;
		if (smallest != i)
			ft_lstswap(i, smallest);
	}
}
