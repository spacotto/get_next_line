/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:03 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/21 17:30:22 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	find_line(t_buffer *sbuffer)
{
	if (sbuffer->start != NULL)
	{
		sbuffer->bookmark = ft_memchr(sbuffer->start, '\n', BUFFER_SIZE);
		sbuffer->start = sbuffer->bookmark;
		return (1);
	}
	else
		return (0);
}

static void	make_line(t_buffer *sbuffer, t_line *sline)
{
	char	*new;
	size_t	old_len;

	old_len = sline->line_len;
	if (!sbuffer->start)
		return ;
	sline->line_len += sline->copy - sbuffer->start + 1;
	new = ft_calloc(sline->line_len + 1, sizeof(char));
	if (!new)
	{
		free(sline->line);
		sline->line = NULL;
		return ;
	}
	if (*sline->line)
		ft_memcpy(new, sline->line, old_len);
	ft_memcpy(new + old_len, sbuffer->start, sline->line_len - old_len);
	new[sline->line_len] = '\0';
	sbuffer->start = sline->copy + 1;
	if (sbuffer->start > sbuffer->end)
		sbuffer->start = NULL;
	free(sline->line);
	sline->line = new;
}

static void	read_line(int fd, t_buffer *sbuffer, t_line *sline)
{
	ssize_t	bytes_read;

	sline->line_len = 0;
	while (!find_line(sbuffer))
	{
		bytes_read = read(fd, sbuffer->buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			{	
				sbuffer->start = NULL; 
				free(sline->line);
				sline->line = NULL;
			}
		sbuffer->start = sbuffer->buffer;
		sbuffer->end = sbuffer->start + bytes_read - 1;
		if (sbuffer->end < sbuffer->start)
			sbuffer->start = NULL;
		if (bytes_read < BUFFER_SIZE)
			break ;
	}
	find_line(sbuffer);
	make_line(sbuffer, sline);
}

char	*get_next_line(int fd)
{
	static t_buffer	b[FD_MAX] = {{{0}, NULL, NULL, NULL}};
	t_line			l;	

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	l.line = NULL;
	read_line(fd, &(b[fd]), &l);
	return (l.line);
}
