/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:40:18 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/19 18:13:48 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	if (ac < 2)
	{
		printf(BOLD RED "ERROR: Invalid format!\n" RESET);
		printf(BOLD YELLOW "Valid format: [1] Number of lines [2] Source file\n" RESET);
	}
	if (ac > 2)
	{
		fd = open(av[2], O_RDONLY);
		if (fd < 0)
			printf(BOLD RED "Invalid source file! " RESET);
		else
		{
			while (i < atoi(av[1]))
			{
				line = get_next_line(fd);
				printf("%s", line);
				i++;
				free(line);				
			}
			close(fd);
		}
	}
	return (0);
}
