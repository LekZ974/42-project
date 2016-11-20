/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 14:22:03 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/20 17:03:54 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		max(char *str)
{
	int		i;

	i = ft_strlen(str);
	ft_putchar('\n');
	ft_putnbr(i);
	ft_putchar('\n');
	if (i > 846294)
	{
		ft_putendl("map too big");
		return (0);
	}
	return (i);
}

int		exist_file(char *file)
{
	int		fd;
	char	buff[BUFF_SIZE];

	fd = open(file, O_RDONLY);
	if (read(fd, buff, BUFF_SIZE) == -1)
	{
		close(fd);
		ft_putendl("file doesn't exist");
		return (1);
	}
	close(fd);
	return (0);
}

int		check_file(char *str)
{
	int		i;
	int		end;

	i = 0;
	end = max(str);
	if (end == 0)
		return (1);
	while (str[i] != '\0')
	{
		while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == ' ' || str[i] == 10 || str[i] == 13)
		{
			printf("str[%d] = [%c]\n", i, str[i]);
			if (i == end)
				return (0);
			i++;
		}
		i++;
		printf("@str[%d] = [%c]\n", i, str[i]);
	}
	ft_putendl("file not valid");
	return (1);
}

char	*fill_str(char *file)
{
	int		fd;
	int		i;
	char	buf[BUFF_SIZE];
	char	*str;

	i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buf, 1))
		i++;
	close(fd);
	fd = open(file, O_RDONLY);
	str = ft_memalloc((sizeof(char)) * i);
	if (str == NULL)
		return (NULL);
	read(fd, str, i);
	close(fd);
	return (str);
}

int		check(char *file)
{
	char	*str;

	if (exist_file(file))
		return (1);
	str = fill_str(file);
	if (check_file(str))
		return (1);
	free(str);
	return (0);
}
