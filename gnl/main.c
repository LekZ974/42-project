/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:31:50 by ahoareau          #+#    #+#             */
/*   Updated: 2016/05/27 17:36:51 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	test_gnl(int test)
{
	int		fd;
	char	**line;

	line = (char **)malloc(sizeof(*line)); 
	if (test == 1)
		fd = open("test/test1.txt", O_RDONLY);
	if (test == 2)
		fd = open("test/test2.txt", O_RDONLY);
	if (test == 3)
		fd = open("test/test3.txt", O_RDONLY);
	if (test == 4)
		fd = open("test/test4.txt", O_RDONLY);
	if (test == 5)
		fd = open("test/test5.txt", O_RDONLY);
	while (get_next_line(fd, line) > 0)
	{
//		 write(fd, *line, ft_strlen(*line));
		printf("###%s###\n", *line);
		free(line);
	}
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
