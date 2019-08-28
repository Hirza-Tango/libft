/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:23:20 by dslogrov          #+#    #+#             */
/*   Updated: 2019/08/28 16:16:47 by dslogrov         ###   ########.fr       */
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

void		ft_hexdump(void *region, size_t size, off_t offset,
	unsigned char pointer_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!region)
		return ;
	while (i < size)
	{
		pad_nbr(offset + i, 1, pointer_size);
		ft_putchar_fd('\t', 1);
		j = 0;
		while (i + j < size && j < 16)
		{
			pad_nbr(*(unsigned char *)(region + i + j++), 1, 2);
			ft_putchar_fd(' ', 1);
		}
		ft_putchar_fd('\n', 1);
		i += 16;
	}
}
