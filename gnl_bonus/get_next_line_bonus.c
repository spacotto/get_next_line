/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:03 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/22 17:40:45 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	search_data(t_buffer *buffer)
{
	buffer->new = ft_memchr(buffer->buffer, '\n', BUFFER_SIZE);
	if (!buffer->new)
		return (0);
	return (1);
}

static void	join_data(t_buffer *buffer, t_line *line)
{
	ft_calloc(line->bytes_read, sizeof(char));
	ft_memcpy();
}

static void	read_data(int fd, t_buffer *buffer, t_line *line)
{
	while (1)
	{
		line->bytes_read = read(fd, buffer->buffer, BUFFER_SIZE);
		buffer->buffer[line->bytes_read] = '\0';
		if (search_data(buffer))
			break ;
		if (line->bytes_read <= 0)
		{
			line->line = NULL;
			return ;
		}
	}
	join_data(buffer, line);
}

char	*get_next_line(int fd)
{
	static t_buffer	b[FD_MAX] = {{{0}, NULL}};
	t_line			l;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	read_data(fd, &b[fd], &l);
	return (l.line);
}
