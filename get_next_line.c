/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:24 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/18 17:23:35 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_line()
{
	
}

static int	make_line()
{

}

static char	*read_line(int fd)
{
	int read_bytes = read(fd, buffer, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	char  *line;
	static t_buffer buffer = {0};
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line();
	return (line);
}
