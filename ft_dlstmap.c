/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:09:49 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/03 17:37:05 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_d_list	*ft_dlstmap(t_d_list *lst, t_d_list *(*f)(t_d_list *elem))
{
	t_d_list	*ret;

	if (!lst || !f)
		return (NULL);
	if (lst->next)
	{
		ret = ft_dlstmap(lst->next, f);
		ft_dlstadd(&ret, f(lst));
	}
	else
		ret = f(lst);
	return (ret);
}
