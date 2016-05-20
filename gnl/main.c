/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:31:50 by ahoareau          #+#    #+#             */
/*   Updated: 2016/05/20 16:24:11 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	test_gnl(int test)
{
	int		fd;
	char	**line;

	if (test == 1)
		fd = open("test/test1.txt", O_RDONLY);
	if (test == 2)
		fd = open("test/test2.txt", O_RDONLY);
	if (test == 3)
		fd = open("test/test3.txt", O_RDONLY);
	if (test == 4)
		fd = open("test/test4.txt", O_RDONLY);
	while (get_next_line(fd, &line) != -1)
	{
		write(fd, line, ft_strlen(line));
		free(line);
	}
	else
		printf("error fd = -1\n");
	close(fd);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		test_gnl(atoi(av[1]));
	}
	else
		printf("wrong number of paramaters\n");
	return (0);
}
