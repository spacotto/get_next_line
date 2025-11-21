/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:14 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/21 17:19:26 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// ============================================================================
// INCLUDES
// ============================================================================

# include <fcntl.h>
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

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

// ============================================================================
// STRUCTURES
// ============================================================================

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE];
	char	*bookmark;
	char	*start;
	char	*end;
}	t_buffer;

typedef struct s_line
{
	char	*line;
	char	*copy;
	size_t  line_len;
}	t_line;

// ============================================================================
// PROTOTYPES
// ============================================================================

// GET NEXT LINE
char	*get_next_line(int fd);

// UTILS
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

// ============================================================================
// COLORS
// ============================================================================

# define RESET 			"\033[0m"

# define GRAY 			"\033[0;90m"
# define RED 			"\033[0;91m"
# define GREEN 			"\033[0;92m"
# define YELLOW 		"\033[0;93m"
# define BLUE 			"\033[0;94m"
# define MAGENTA		"\033[0;95m"
# define CYAN 			"\033[0;96m"
# define WHITE 			"\033[0;97m"

# define BOLD_GRAY 		"\033[1;90m"
# define BOLD_RED 		"\033[1;91m"
# define BOLD_GREEN 	"\033[1;92m"
# define BOLD_YELLOW	"\033[1;93m"
# define BOLD_BLUE		"\033[1;94m"
# define BOLD_MAGENTA 	"\033[1;95m"
# define BOLD_CYAN 		"\033[1;96m"
# define BOLD_WHITE 	"\033[1;97m"

#endif
