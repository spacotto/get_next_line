/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:33 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/17 16:06:56 by spacotto         ###   ########.fr       */
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
#  define BUFFER_SIZE 4096 
# endif

// ============================================================================
// PROTOTYPES
// ============================================================================

// GET NEXT LINE
char	*get_next_line(int fd);

// UTILS
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif
