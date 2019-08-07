/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:23:20 by dslogrov          #+#    #+#             */
/*   Updated: 2019/08/07 15:29:15 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pad_nbr(size_t num, int fd, size_t padding)
{
	size_t	size;
	size_t	tmp;

	tmp = num;
	size = padding - 1;
	while ((tmp /= 16))
		size--;
	while (size--)
		ft_putchar_fd('0', fd);
	ft_put_uintmax_base_fd(num, fd, 16);
}

void		ft_hexdump(void *region, size_t size, off_t offset, int fd)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!region)
		return ;
	while (i < size)
	{
		pad_nbr(offset + i, fd, 16);
		ft_putchar_fd('\t', fd);
		j = 0;
		while (i + j < size && j < 16)
		{
			pad_nbr(*(unsigned char *)(region + i + j++), fd, 2);
			ft_putchar_fd(' ', fd);
		}
		ft_putchar_fd('\n', fd);
		i += 16;
	}
}
