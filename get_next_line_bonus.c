/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:03 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/20 17:03:52 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	find_eol(t_buffer *buffer, char **copy_til)
{
	size_t	i;

	i = 0;
	if (buffer->start == NULL)
		return (0);
	while (buffer->start + i <= buffer->end)
	{
		if (buffer->start[i] == '\n')
		{
			*copy_til = buffer->start + i;
			return (1);
		}
		i++;
	}
	*copy_til = buffer->end;
	return (0);
}

static int	line_aggregation(t_buffer *buffer, char **copy_til, char **line,
								size_t *len)
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

static char	*ft_read_line(int fd, t_buffer *buffer, char **line)
{
	char	*copy_til;
	size_t	line_length;
	ssize_t	bytes_read;

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
	static t_buffer	buffer[FD_MAX] = {{{0}, NULL, NULL}};
	char			*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	return (ft_read_line(fd, &(buffer[fd]), &line));
}
