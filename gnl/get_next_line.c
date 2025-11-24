/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:24 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/24 16:09:29 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	search_data(t_buffer *buff)
{
	if (buff->start >= buff->end)
		return (0);
	buff->new_line = ft_memchr(buff->start, '\n', buff->end - buff->start);
	if (buff->new_line)
		return (1);
	return (0);
}

static void	join_data(t_buffer *buffer, t_line *line)
{
	char	*line_tmp; // [4]
	size_t	line_len;
	size_t	chunk_len;

	line_len = 0;
	if (line->line)
		line_len = ft_strlen(line->line);
	chunk_len = buffer->end - buffer->start;
	if (buffer->new_line)
		chunk_len = (buffer->new_line - buffer->start) + 1;
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
		if (!buffer->start || buffer->start >= buffer->end)
		{
			line->bytes_read = read(fd, buffer->buffer, BUFFER_SIZE);
			if (line->bytes_read <= 0)
			{
				line->line = NULL; // [1]
				return ;
			}
			buffer->buffer[line->bytes_read] = '\0';
			buffer->start = buffer->buffer;
			buffer->end = buffer->start + line->bytes_read;
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
	static t_buffer	b = {{0}, NULL, NULL, NULL};
	t_line			l;

	l.line = NULL; // [1]
	l.bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (l.line);
	read_data(fd, &b, &l);
	return (l.line);
}

// NOTES
// [1]	Initialise the line that will be returned to NULL, and reset it every 
// 		time an error occurs. This way, the return value will always be either
// 		the line we got or NULL.
// [2]	Given that gnl shall be called in while loops and tested with different
//		buffer sizes, we shall check if our buffer has already been filled. In
//		fact, when we use big BUFFER_SIZE, we don't need to perform further 
//		readings, for we've gathered all the necessary data.
// [3]	Once we find the end of the line (\n or \0), we can start composing the 
//		line we will return.
// [4]	When BUFFER_SIZE is too small to contain the whole line, we need to 
// 		aggregate the line chunk by chunk. To do so, we need a tmp to which
// 		we will keep adding the chunks extracted from the buffer. This way,
// 		every time we read, we won't lose the initial pointer of the line.
