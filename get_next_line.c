/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:24 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/19 17:13:28 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Given that gnl shall be called in while loops, it's better to start with the
// assumption that our buffer has already been filled. In fact, when we use big
// BUFFER_SIZE, we don't need to perform further readings, for we've gathered
// all the necessary data.
static int	find_line(t_buffer *buffer)
{
	
}

// Once we find the end of the line (\n or \0), we can start composing the line
// we will return.
static int	make_line(t_buffer *buffer)
{

}

static char	*read_line(int fd, t_buffer *buffer)
{
	int read_bytes = read(fd, buffer, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	char  *line;
	static t_buffer buffer = {{0}, NULL}; // Declaring the whole structure as static requires the init of all its elements 
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line();
	return (line);
}
