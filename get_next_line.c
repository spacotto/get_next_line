/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:24 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/19 17:44:40 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//	Given that gnl shall be called in while loops, it's better to start with the
//	assumption that our buffer has already been filled. In fact, when we use big
//	BUFFER_SIZE, we don't need to perform further readings, for we've gathered
// 	all the necessary data.
static int	find_line(t_buffer *buffer, char **copy)
{
	size_t	i;

	i = 0;
	if (buffer->start == NULL)
		return (0);
	while (buffer->start + i <= buffer->end)
	{
		if (buffer->start[i] == '\n')
		{
			*copy = buffer->start + i;
			return (1);
		}
		i++;
	}
	*copy = buffer->end;
	return (0);
}

//	Once we find the end of the line (\n or \0), we can start composing the line
//	we will return.
static int	make_line(t_buffer *buffer)
{
	char	*new;
	size_t	old_len;

	old_len = *len;
	if (!buffer->start)
		return (1);
	*len += *copy_til - buffer->start + 1;
	new = malloc((*len + 1) * sizeof(char));
	if (!new)
	{
		free(*line);
		line = NULL;
		return (0);
	}
	if (*line)
		ft_memcpy(new, *line, old_len);
	ft_memcpy(new + old_len, buffer->start, *len - old_len);
	new[*len] = '\0';
	buffer->start = *copy_til + 1;
	if (buffer->start > buffer->end)
		buffer->start = NULL;
	free(*line);
	*line = new;
	return (1);
}

static char	*read_line(int fd, t_buffer *buffer)
{
	t_read	r;

	line_length = 0;
	while (!find_eol(buffer, &copy_til))
	{
		if (!line_aggregation(buffer, &copy_til, line, &line_length))
			return (NULL);
		bytes_read = read(fd, buffer->buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (buffer->start = NULL, free(*line), NULL);
		buffer->start = buffer->buffer;
		buffer->end = buffer->start + bytes_read - 1;
		if (buffer->end < buffer->start)
			buffer->start = NULL;
		if (bytes_read < BUFFER_SIZE)
			break ;
	}
	find_eol(buffer, &copy_til);
	if (!line_aggregation(buffer, &copy_til, line, &line_length))
		return (NULL);
	return (*line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_buffer	buffer = {{0}, NULL, NULL}; 
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, &(buffer[fd]), &line);
	return (line);
}
