/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:03 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/21 15:53:43 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	find_line(t_buffer *buffer, char **copy_til)
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

static void	make_line(t_buffer *buffer, char **copy_til, t_line *sline)
{
	char	*new;
	size_t	old_len;

	old_len = sline->line_len;
	if (!buffer->start)
		return ;
	sline->line_len += *copy_til - buffer->start + 1;
	new = malloc((sline->line_len + 1) * sizeof(char));
	if (!new)
	{
		free(sline->line);
		sline->line = NULL;
		return ;
	}
	if (*sline->line)
		ft_memcpy(new, sline->line, old_len);
	ft_memcpy(new + old_len, buffer->start, sline->line_len - old_len);
	new[sline->line_len] = '\0';
	buffer->start = *copy_til + 1;
	if (buffer->start > buffer->end)
		buffer->start = NULL;
	free(sline->line);
	sline->line = new;
}

static void	read_line(int fd, t_buffer *buffer, t_line *sline)
{
	char	*copy_til;
	ssize_t	bytes_read;

	sline->line_len = 0;
	while (!find_line(buffer, &copy_til))
	{
		bytes_read = read(fd, buffer->buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			{	
				buffer->start = NULL; 
				free(sline->line);
				sline->line = NULL;
			}
		buffer->start = buffer->buffer;
		buffer->end = buffer->start + bytes_read - 1;
		if (buffer->end < buffer->start)
			buffer->start = NULL;
		if (bytes_read < BUFFER_SIZE)
			break ;
	}
	find_line(buffer, &copy_til);
	make_line(buffer, &copy_til, sline);
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer[FD_MAX] = {{{0}, NULL, NULL}};
	t_line			l;	

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	l.line = NULL;
	read_line(fd, &(buffer[fd]), &l);
	return (l.line);
}
