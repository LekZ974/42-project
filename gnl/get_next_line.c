/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:34:15 by ahoareau          #+#    #+#             */
/*   Updated: 2016/06/16 18:51:03 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

char	*ft_takeline(char **save, char **line)
{
	char		*pos;

	pos = ft_strchr(*save, '\n');
	if (pos)
		*pos = 0;
	if (!*line)
		*line = ft_strdup(*save);
	else
		*line = ft_strjoin((char *)*line, *save);
	if (pos && pos[1])
	{
		*save = ft_strcpy(*save, pos + 1);
	}
	else if ((pos && !pos[1]) || !pos)
		ft_bzero((void *)*save, ft_strlen(*save));
	return (pos);
}

int		ft_read(int const fd, char **save, char **line)
{
	char		*pos;
	int			gnl;

	gnl = 1;
	pos = NULL;
	while (gnl != 0)
	{
		gnl = read(fd, *save, BUFF_SIZE);
		if (gnl < 0)
			return (-1);
		if (gnl == 0)
			return (0);
		(*save)[gnl] = 0;
		pos = ft_takeline(save, &(*line));
		if (pos)
			return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_fd	save;
	int			gnl;
	char		*ret;

	*line = NULL;
	gnl = 0;
	if (BUFF_SIZE < 0 || fd < 0 || line == NULL)
		return (-1);
	if (save.prev_fd != fd)
	{
		ft_memdel((void **)&save.stock);
		save.prev_fd = fd;
	}
	if (!save.stock)
	{
		save.stock = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		ft_bzero(save.stock, ft_strlen(save.stock));
	}
	if (ft_strchr((save.stock), '\n') || save.stock[0])
	{
		ret = ft_takeline(&save.stock, &(*line));
		if (ret)
			gnl = 1;
	}
	if (gnl == 0)
	{
		gnl = ft_read(fd, &save.stock, &(*line));
		if (gnl == 0 && !*line)
			free(save.stock);
	}
	if (*line)
		gnl = 1;
	return (gnl);
}
