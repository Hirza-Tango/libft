/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:45:35 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/17 13:31:30 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_atou_base(const char *value, unsigned char base)
{
	char			*byte;
	size_t			result;
	unsigned char	curr;

	byte = (char *)value;
	while (ft_isspace(*byte))
		byte++;
	result = 0;
	while (1)
	{
		curr = ft_isdigit(*byte) ? *byte - '0' : *byte - 'A' + 10;
		if (!ft_isalnum(*byte) || curr >= base)
			break ;
		result = result * 10 + curr;
		byte++;
	}
	return (result);
}