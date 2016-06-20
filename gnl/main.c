/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:06:49 by ahoareau          #+#    #+#             */
/*   Updated: 2016/06/19 15:12:46 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

#include "libft/libft.h"

void	input1(int testnum)
{
	int		fd;
	int		ret;
	char	*line = NULL;
	int		stop = 0;

	if (testnum == 1)
		fd = open("test01", O_RDONLY);
	if (testnum == 2)
		fd = open("test02", O_RDONLY);
	if (testnum == 3)
		fd = open("test03", O_RDONLY);
	if (testnum == 4)
		fd = open("test04", O_RDONLY);
	if (testnum == 5)
		fd = open("test05", O_RDONLY);
	if (testnum == 6)
		fd = open("test06", O_RDONLY);
	if (testnum == 7)
		fd = open("test07", O_RDONLY);
	if (testnum == 8)
		fd = open("test08", O_RDONLY);
	if (testnum == 9)
		fd = open("test09", O_RDONLY);
	if (testnum == 10)
		fd = -1;
	if (testnum == 11)
		fd = open("test11", O_RDONLY);
	if (testnum == 12)
	{
		fd = open("test01", O_RDONLY);	
		printf("\n\tpremier sous-test\n");
		while ((ret = get_next_line(fd, &line)) >= 0)
		{
			printf("\n\t***ret gnl : %d line : [%s]***\n", ret, line);
			if (ret == 0)
				break ;
			stop++;
		}
		if (fd != STDIN_FILENO && fd != STDOUT_FILENO && fd != STDERR_FILENO)
			close(fd);
		printf("\n\tsecond  sous-test\n");
		fd = open("test03", O_RDONLY);
		while ((ret = get_next_line(fd, &line)) >= 0)
		{
			printf("\n\t***ret gnl : %d line : [%s]***\n", ret, line);
			if (ret == 0)
				break ;
			stop++;
		}
		if (fd != STDIN_FILENO && fd != STDOUT_FILENO && fd != STDERR_FILENO)
			close(fd);
		return ;
	}
	if (testnum == 13)
		fd = open("test13", O_RDONLY);
	if (testnum == 14)
	{
		int		new_fd;
		fd = open("test01", O_RDONLY);	
		printf("\n\tpremier sous-test\n");
		ret = get_next_line(fd, &line);
		printf("\n\t***ret gnl : %d line : [%s]***\n", ret, line);
		printf("\n\tsecond  sous-test\n");
		new_fd = open("test03", O_RDONLY);
		ret = get_next_line(new_fd, &line);
		printf("\n\t***ret gnl : %d line : [%s]***\n", ret, line);
		if (fd != STDIN_FILENO && fd != STDOUT_FILENO && fd != STDERR_FILENO)
		{
			close(fd);
			close(new_fd);
		}
		return ;
	}
	if (testnum == 15)
	{
		printf("%d\n", get_next_line(-99, NULL));
		printf("%d\n", get_next_line(-1, NULL));
		printf("%d\n", get_next_line(-10000, NULL));
		printf("%d\n", get_next_line(1, NULL));
		printf("%d\n", get_next_line(99, NULL));
	}
	while ((ret = get_next_line(fd, &line)) >= -1)
	{
		printf("\n\t***ret gnl : %d line : [%s]***\n", ret, line);
		if (ret == 0 || ret == -1)
			break ;
		stop++;
	}
	if (fd != STDIN_FILENO && fd != STDOUT_FILENO && fd != STDERR_FILENO)
		close(fd);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		input1(ft_atoi(av[1]));
	}
	else
		printf("wrong number of arguments for main.c\n");
	return (0);
}
