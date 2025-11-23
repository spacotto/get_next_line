/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:24 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/19 18:53:14 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
				line->line = NULL; // [1]
				return ;
			}
			buffer->buffer[line->bytes_read] = '\0';
			buffer->old = buffer->buffer;
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
	t_buffer	b;
	t_line		l;
	static char	buffer[BUFFER_SIZE];
	static char	*old;
	static char	*new;

	l.line = NULL; // [1]
	l.bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (l.line);
	read_data(fd, &b[fd], &l);
	return (l.line);
}

//	NOTES
// [1]	Initialise the line that will be returned to NULL, and reset it every time
//		an error occurs. This way, the return value will always be either the line
//		we got or NULL.
// [2]	Given that gnl shall be called in while loops and tested with different
//		buffer sizes, we shall check if our buffer has already been filled. In fact, 
//		when we use big BUFFER_SIZE, we don't need to perform further readings, for 
//		we've gathered all the necessary data.
// [3]	Once we find the end of the line (\n or \0), we can start composing the 
//		line we will return.
////////////////////////////////////////////////////////////////////////////////
