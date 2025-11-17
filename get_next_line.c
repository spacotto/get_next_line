/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:24 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/17 16:09:07 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char  *read_line()

char	*get_next_line(int fd)
{
  char  *line;
  static char buffer[BUFFER_SIZE] = {0};
  ssize_t len;
  char *found;

  if (memchr(buffer, '\n', strlen(buffer))
  {
    handle_it;
  }

  while (1)
    {
     len = read(fd, buffer, BUFFER_SIZE);
      buffer[len] = 0;
      if (len < 0)
        return (NULL);
      if (memchr(buffer, '\n', len) || len == 0)
        break; 
    }
  found = memchr(buffer, '\n', len);
  if (found)
  {
    line = calloc(sizeof(char), len - strlen(found));
    line = memmove(line, found, len - strlen(found));
  }
  buffer = buffer + (len - strlen(found));
  return (line);
}
