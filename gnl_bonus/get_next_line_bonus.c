/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:03 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/22 19:15:11 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	search_data(t_buffer *buffer)
{
	if (!buffer->old)
		return (0);
	buffer->new = ft_memchr(buffer->old, '\n', ft_strlen(buffer->old));
	if (buffer->new)
		return (1);
	return (0);
}

static void	join_data(t_buffer *buffer, t_line *line)
{
	char	*origin;
	size_t	len_line;
	size_t	len_chunk;

	len_line = 0;
	if (line->line)
		len_line = ft_strlen(line->line);
	len_chunk = ft_strlen(buffer->old);
	if (buffer->new)
		len_chunk = (buffer->new - buffer->old) + 1;
	origin = ft_calloc(len_line + len_chunk + 1, sizeof(char));
	if (!origin)
		return ;
	if (line->line)
	{
		ft_memcpy(origin, line->line, len_line);
		free(line->line);
	}
	ft_memcpy(origin + len_line, buffer->old, len_chunk);
	origin[len_line + len_chunk] = '\0';
	line->line = origin;
	buffer->old += len_chunk;
}

static void	read_data(int fd, t_buffer *buffer, t_line *line)
{
	while (1)
	{
		if (!buffer->old || !*buffer->old)
		{
			line->bytes_read = read(fd, buffer->buffer, BUFFER_SIZE);
			if (line->bytes_read <= 0)
			{
				line->line = NULL;
				return ;
			}
			buffer->buffer[line->bytes_read] = '\0';
			buffer->old = buffer->buffer;
		}
		if (search_data(buffer))
		{
			join_data(buffer, line);
			return ;
		}
		join_data(buffer, line);
	}
}

char	*get_next_line(int fd)
{
	static t_buffer	b[FD_MAX] = {{{0}, NULL, NULL}};
	t_line			l;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	l.line = NULL;
	l.bytes_read = 0;
	read_data(fd, &b[fd], &l);
	return (l.line);
}
