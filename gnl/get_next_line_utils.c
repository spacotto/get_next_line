/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:22:50 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/18 15:02:27 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *str;
    size_t          i;

    str = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        str[i] = c;
        i++;
    }
    return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*t;

	t = malloc(nmemb * size);
	if (t)
	{
		ft_memset(t, '\0', nmemb * size);
		return (t);
	}
	return (NULL);
}

void    *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *str;
    unsigned char       target;
    size_t              i;

    str = (const unsigned char *)s;
    target = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        if (str[i] == target)
            return ((void *)&str[i]);
        i++;
    }
    return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
