/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:40:18 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/21 16:29:37 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	if (ac < 2 || atoi(av[1]) == 0)
	{
		printf(BOLD_RED "ERROR: Invalid format!\n" RESET);
		printf(YELLOW "Valid format: [1] Number of lines [2] Source file\n" RESET);
	}
	if (ac > 2)
	{
		int fd = open(av[2], O_RDONLY);
		if (fd < 0)
			printf(BOLD_RED "Invalid source file! " RESET);
		else
		{
			int i = 0;
			while (i < atoi(av[1]))
			{
				char *line = get_next_line(fd);
				printf("%s", line);
				free(line);
				i++;				
			}
		}
		close(fd);
	}
	return (0);
}
