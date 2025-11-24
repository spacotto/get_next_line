/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:40:18 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/24 17:25:35 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	main(int ac, char **av)
{
	if (ac < 4)
	{
		printf(BOLD_RED "ERROR: not enough arguments!\n" RESET);
		printf(YELLOW "Valid format: [1] Number of lines [2] Mode stdin (ON/OFF) [3] Source file\n" RESET);
		return (-1);
	}
	if (ac > 4)
	{
		printf(BOLD_RED "ERROR: too many arguments!\n" RESET);
		printf(YELLOW "Valid format: [1] Number of lines [2] Mode stdin (ON/OFF) [3] Source file\n" RESET);
		return (-1);
	}
	if (ac == 4)
	{
		if (atoi(av[1]) == 0)
		{
			printf(BOLD_RED "Error: invalid number of lines!\n" RESET);
			printf(YELLOW "Valid format: [1] Number of lines [2] Mode stdin (ON/OFF) [3] Source file\n" RESET);
			return (-1);
		}
		if (strcmp("ON", av[2]) == 0)
		{
			char *line = get_next_line(0);
			printf("%s", line);
			free(line);
			return(0);
		}
		int fd = open(av[3], O_RDONLY);
		if (fd < 0)
		{
			printf(BOLD_RED "Error: invalid source file!\n" RESET);
			printf(YELLOW "Valid format: [1] Number of lines [2] Mode stdin (ON/OFF) [3] Source file\n" RESET);
			close(fd);
			return (-1);
		}
		int i = 0;
		while (i < atoi(av[1]))
		{
			char *line = get_next_line(fd);
			printf("%s", line);
			free(line);
			i++;				
		}
		close(fd);
	}
	return (0);
}
