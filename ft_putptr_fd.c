/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:10:27 by dslogrov          #+#    #+#             */
/*   Updated: 2019/06/27 16:17:50 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(void *ptr, int fd)
{
	uintmax_t n;

	n = (uintmax_t)ptr;
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else if (n < 16)
		ft_putchar_fd(n - 10 + 'A', fd);
	else
	{
		ft_putnbr_fd(n / 16, fd);
		if (n % 16 < 10)
			ft_putchar_fd(n % 16 + '0', fd);
		else
			ft_putchar_fd(n % 16 - 10 + 'A', fd);
	}
}
