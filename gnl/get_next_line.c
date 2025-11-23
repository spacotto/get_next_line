/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:24 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/23 20:53:17 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
				line->line = NULL; // [1]
				return ;
			}
			buffer->buffer[line->bytes_read] = '\0';
			buffer->start = buffer->buffer;
		}
		if (search_data(buffer)) // [2]
		{
			join_data(buffer, line); // [3]
			return ;
		}
		join_data(buffer, line);
	}
}

char	*get_next_line(int fd)
{
	static t_buffer	b = {{0}, NULL, NULL};
	t_line			l;

	l.line = NULL; // [1]
	l.bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (l.line);
	read_data(fd, &b, &l);
	return (l.line);
}

//	NOTES
// [1]	Initialise the line that will be returned to NULL, and reset it every 
// 		time an error occurs. This way, the return value will always be either
// 		the line we got or NULL.
// [2]	Given that gnl shall be called in while loops and tested with different
//		buffer sizes, we shall check if our buffer has already been filled. In
//		fact, when we use big BUFFER_SIZE, we don't need to perform further 
//		readings, for we've gathered all the necessary data.
// [3]	Once we find the end of the line (\n or \0), we can start composing the 
//		line we will return.
