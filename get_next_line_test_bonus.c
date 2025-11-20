/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:00:51 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/20 18:26:32 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <string.h>

static void	open_files(int **fd, int ac, char **av)
{
	int i = 0;
	int f = 2;
	while (f < ac)
	{
		fd[i] = open(av[f], O_RDONLY);
		if (fd[i] < 0)
		{
			printf(BOLD RED "Invalid source file!" RESET);
			close_files(fd, i);
			return (-1);
		}
		i++;
		f++;
	}
}

static void	close_files(int **fd, int open)
{
	int i = 0;
	while (fd[i] <= open)
	{
		close(fd[i]);
		i++;
	}
}


int	main(int ac, char **av)
{
	int fd[FD_MAX] = {0};
	int lines = 0;
	int files = 2;
	
	if (ac <= 2 || atoi(av[1]) == 0)
	{
		printf(BOLD RED "ERROR: Invalid format!\n" RESET);
		printf(BOLD YELLOW "Valid format: [1] Number of lines [2] Source file(s)\n" RESET);
	}
	if (ac > 2)
	{
		open_files(fd, ac, av);
		int i = 0;
		while (lines < atoi(av[1]))
		{
			while (files < ac)
			{
				char *line = get_next_line(fd[i]);
				printf(YELLOW "File [%d] Line [%d]\n" RESET, fd[i], lines + 1);
				printf("%s", line);
				free(line);
				i++;
			}
			lines++;
		}
		close(fd, ac - 2);
	}
	return (0);
}
