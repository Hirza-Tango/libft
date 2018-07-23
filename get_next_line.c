/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:48:49 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/23 13:54:36 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_file_buffer(size_t fd, t_list **start)
{
	t_list	*tmp;

	tmp = *start;
	while (tmp)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(start, tmp);
	return (tmp);
}

static size_t	ft_endl_pos(const char *s)
{
	char	*c;

	c = (char *)s;
	while (*c && *c != '\n')
		c++;
	return (c - s);
}

int				get_next_line(const int fd, char **line)
{
	char			l_b[BUFF_SIZE + 1];
	size_t			bytes_read;
	static t_list	*buffer_list;
	t_list			*f_b;

	CHECK_RETURN(fd < 0 || line == NULL || read(fd, l_b, 0) < 0, -1);
	f_b = get_file_buffer(fd, &buffer_list);
	if (!f_b->content)
		f_b->content = ft_strnew(1);
	while ((bytes_read = read(fd, l_b, BUFF_SIZE)))
	{
		l_b[bytes_read] = 0;
		ft_swapnfree((char **)&f_b->content, ft_strjoin(f_b->content, l_b));
		CHECK_RETURN(!f_b->content, -1);
		if (ft_strchr(f_b->content, '\n'))
			break ;
	}
	CHECK_RETURN(bytes_read < BUFF_SIZE && !*(char *)(f_b->content), 0);
	*line = ft_strndup(f_b->content, ft_endl_pos(f_b->content));
	if (ft_strlen(*line) < ft_strlen(f_b->content))
		ft_swapnfree((char **)&f_b->content,
			ft_strdup(f_b->content + ft_strlen(*line) + 1));
	else
		ft_strdel((char **)&f_b->content);
	return (1);
}
