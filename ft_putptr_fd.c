/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:10:27 by dslogrov          #+#    #+#             */
/*   Updated: 2019/06/27 16:46:56 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(void *ptr, int fd)
{
	ft_putstr_fd("0x", fd);
	ft_put_uintmax_base_fd((uintmax_t)ptr, fd, -16);
}
