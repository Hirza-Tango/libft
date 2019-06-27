/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:10:27 by dslogrov          #+#    #+#             */
/*   Updated: 2019/06/27 16:23:06 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(void *ptr, int fd)
{
	uintmax_t	n;
	static char init;

	if (!init)
		ft_putstr_fd("0x", fd);
	init = 1;
	n = (uintmax_t)ptr;
	if (n < 16)
	{
		if (n < 10)
			ft_putchar_fd(n + '0', fd);
		else
			ft_putchar_fd(n - 10 + 'A', fd);
		init = 0;
	}
	else
	{
		ft_putptr_fd((void *)(n / 16), fd);
		if (n % 16 < 10)
			ft_putchar_fd(n % 16 + '0', fd);
		else
			ft_putchar_fd(n % 16 - 10 + 'A', fd);
	}
}
