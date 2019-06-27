/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uintmax_base_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:32:31 by dslogrov          #+#    #+#             */
/*   Updated: 2019/06/27 17:00:28 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_uintmax_base_fd(uintmax_t n, int fd, int base)
{
	char caps;

	caps = (base < 0);
	if (base < 0)
		base *= -1;
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else if (n < (unsigned)base && caps)
		ft_putchar_fd(n - 10 + 'A', fd);
	else if (n < (unsigned)base)
		ft_putchar_fd(n - 10 + 'a', fd);
	else
	{
		ft_put_uintmax_base_fd(n / (unsigned)base, fd, base);
		if (n % base < 10)
			ft_putchar_fd(n % base + '0', fd);
		else if (caps)
			ft_putchar_fd(n % base - 10 + 'A', fd);
		else
			ft_putchar_fd(n % base - 10 + 'a', fd);
	}
}
