/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:00:51 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/20 16:46:47 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <string.h>

int	main(int ac, char **av)
{
	static int fd[FD_MAX] = {0};
	static int i = 0;
	if (ac <= 2)
	{
		printf(BOLD RED "ERROR: Invalid format!\n" RESET);
		printf(BOLD YELLOW "Valid format: [1] Number of lines [2] Source file(s)\n" RESET);
	}
	if (ac > 2)
	{
		int files = 2;
		while (files < ac)
		{
			fd[i] = open(av[files], O_RDONLY);
			if (fd[i] < 0)
			{
				printf(BOLD RED "Invalid source file!" RESET);
				return (-1);	
			}
			int lines = 0;
			while (lines < atoi(av[1]))
			{
				char *line = get_next_line(fd[i]);
				printf("%s", line);
				free(line);
				lines++;
			}
			i++;
			files++;
		}
		i = 0;
		while (fd[i] < ac - 2)
		{
			close(fd[i]);
			i++;
		}
	}
	return (0);
}
