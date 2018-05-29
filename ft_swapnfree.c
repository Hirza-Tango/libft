/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapnfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:32:13 by dslogrov          #+#    #+#             */
/*   Updated: 2018/05/29 15:15:23 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapnfree(char **var, char *new_val)
{
	char	*temp;

	temp = new_val;
	free(*var);
	*var = temp;
}
