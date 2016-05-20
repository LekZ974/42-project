/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:48:21 by ahoareau          #+#    #+#             */
/*   Updated: 2016/05/20 18:22:28 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	size_line(char *line)
{
	int		size;

	size = 0;
	while (line[size] != '\n' || line[size] != EOF)
		size++;
	return (size);
}

static char	*read_line(char **line)
{
	int			i;
	static char	*stock;

	i = 0;
	stock = (char*)malloc(sizeof(char) * size_line(*line) + 1);
	while (*line[i] && i < BUFF_SIZE)
	{
		if (*line[i] == '\n' || *line[i] == EOF)
		{
			stock[i] = '\0';
			return (*line);
		}
		stock[i] = *line[i];
		i++;
	}
	return (stock);
}

int		get_next_line(const int fd, char **line)
{
	static char		*read_line;

	read_line = read_line(line);
	if (fd <= 0 || line == NULL || read_line == NULL) 
		return (-1);
	if (read_line(line) && fd > 0)
		return (1);
	return (0);
}
