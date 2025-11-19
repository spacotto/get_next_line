/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:33 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/19 17:42:15 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// ============================================================================
// INCLUDES
// ============================================================================

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// ============================================================================
// DEFINES
// ============================================================================

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4 
# endif

// ============================================================================
// STRUCTURES
// ============================================================================

typedef struct	s_buffer
{
	char	buffer[BUFFER_SIZE];
	char	*start;
	char	*end;
}	t_buffer;

typedef struct	s_read
{
	char	*copy;
	size_t	len;
	ssize_t	bytes_read;
}	t_read;

// ============================================================================
// PROTOTYPES
// ============================================================================

// GET NEXT LINE
char	*get_next_line(int fd);

// UTILS
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);

// ============================================================================
// COLORS
// ============================================================================

# define BOLD "\033[1m"
# define RESET "\033[0m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

#endif
