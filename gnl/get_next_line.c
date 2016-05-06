/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:48:21 by ahoareau          #+#    #+#             */
/*   Updated: 2016/05/06 17:46:52 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	fill_line(const int fd, char **line)
{
	static char	buf[BUF_SIZE];
	static int		i;
	static int		end;

	i = 0;
	if (i == 0 || i == end)
		end = read(fd, buf, BUF_SIZE);
	while(read(fd, buf, 1) != EOF)
	{
		if (buf[i] == '\n' || buf[i] == '\0')
		{
			*line = ft_strdup(buf);
			return (buf[i]);
		}
		i++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	t_line	*ptr;
	char 	buf[BUF_SIZE];

	ptr = malloc(sizeof(char*)*(BUF_SIZE) + 1);
	ptr->data = fill_line(fd, line);
	if (fill_line(fd, line) == '\0' || fill_line(fd, line) == '\n')
	{
		if (fill_line(fd, line) == '\n')
			return (1);
		if (fill_line(fd, line) == '\0')
			return (0);
	}
	return (-1);
}
