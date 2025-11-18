/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spacotto <spacotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:40:18 by spacotto          #+#    #+#             */
/*   Updated: 2025/11/18 15:43:01 by spacotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	int	i;

	i = 0;
	if (ac == 1)
	{
		printf(BOLD RED "ERROR! " RESET);
		printf("Missing number of lines && FD");
	}
	if (ac == 2)
	{
		printf(BOLD RED "ERROR! " RESET);
		printf("Missing number of lines || FD");
	}
	if (ac > 2)
	{
		fd = open(av[2], O_RDONLY);
		while (i < atoi(av[1]))
		{
			printf("%s", get_next_line(fd));
			i++;
		}
		close(fd);
	}
	return (0);
}
