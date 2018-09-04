/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapnfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:32:13 by dslogrov          #+#    #+#             */
/*   Updated: 2018/09/04 16:04:36 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapnfree(void **var, void *new_val)
{
	void	*temp;

	temp = new_val;
	free(*var);
	*var = temp;
}
