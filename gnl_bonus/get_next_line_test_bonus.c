/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:00:51 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/21 12:42:59 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	close_files(int *fd, int open)
{
	int i = 0;
	while (i <= open)
	{
		close(fd[i]);
		i++;
	}
	return (0);
}

static int	open_files(int *fd, int ac, char **av)
{
	int i = 0;
	while (i < ac - 2)
	{
		fd[i] = open(av[i + 2], O_RDONLY);
		if (fd[i] < 0)
		{
			printf(BOLD_RED "ERROR: Invalid source file(s)!" RESET);
			close_files(fd, i);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int fd[FD_MAX] = {0};
	int l = 0;	// The line we're getting 
	int f = 0;	// The file from which we're getting the line

	if (ac <= 2 || atoi(av[1]) == 0)
	{
		printf(BOLD_RED "ERROR: Invalid format!\n" RESET);
		printf(YELLOW "Valid format: [1] Number of lines [2] Source file(s)\n" RESET);
	}
	if (ac > 2)
	{
		printf(BOLD_CYAN "GIVE ME A LINE!\n" RESET);
		char *line = get_next_line(0);
		printf("%s", line);
		free(line);
		if (open_files(fd, ac, av) == -1)
			return (-1);
		while (l < atoi(av[1]))
		{
			f = 0;
			printf(BOLD_CYAN "\nGET NEXT LINE!\n" RESET);
			while (f < ac - 2)
			{
				line = get_next_line(fd[f]);
				printf(YELLOW "\nFile [%d] Line [%d]\n" RESET, fd[f], l);
				printf("%s", line);
				free(line);
				f++;
			}
			l++;
		}
		close_files(fd, ac - 2);
	}
	return (0);
}
