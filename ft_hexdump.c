#include "libft.h"

void	ft_hexdump(void *region, size_t size, int fd)
{
	size_t			i;
	
	i = 0;
	if (!region)
		return ;
	while (i < size)
	{
		ft_printf_fd(fd, "%0zu %0hhx", region + i, *(region + i++));
		while (i < size && i % 8)
			ft_printf(fd, " %0hhx", *(region + i++));
		ft_putchar('\n');
	}
}
