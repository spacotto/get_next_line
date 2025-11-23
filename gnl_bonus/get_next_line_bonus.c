/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:03 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/23 19:01:22 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	search_data(t_buffer *buffer)
{
	if (!buffer->start)
		return (0);
	buffer->end = ft_memchr(buffer->start, '\n', ft_strlen(buffer->start));
	if (buffer->end)
		return (1);
	return (0);
}

static void	join_data(t_buffer *buffer, t_line *line)
{
	char	*line_tmp;
	size_t	line_len;
	size_t	chunk_len;

	line_len = 0;
	if (line->line)
		line_len = ft_strlen(line->line);
	chunk_len = ft_strlen(buffer->start);
	if (buffer->end)
		chunk_len = (buffer->end - buffer->start) + 1;
	line_tmp = ft_calloc(line_len + chunk_len + 1, sizeof(char));
	if (!line_tmp)
		return ;
	if (line->line)
	{
		ft_memcpy(line_tmp, line->line, line_len);
		free(line->line);
	}
	ft_memcpy(line_tmp + line_len, buffer->start, chunk_len);
	line->line = line_tmp;
	buffer->start += chunk_len;
}

static void	read_data(int fd, t_buffer *buffer, t_line *line)
{
	while (1)
	{
		if (!buffer->start || !*buffer->start)
		{
			line->bytes_read = read(fd, buffer->buffer, BUFFER_SIZE);
			if (line->bytes_read <= 0)
			{
				line->line = NULL;
				return ;
			}
			buffer->buffer[line->bytes_read] = '\0';
			buffer->start = buffer->buffer;
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

	l.line = NULL;
	l.bytes_read = 0;
	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (l.line);
	read_data(fd, &b[fd], &l);
	return (l.line);
}
