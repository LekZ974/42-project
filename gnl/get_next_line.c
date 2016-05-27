/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:48:21 by ahoareau          #+#    #+#             */
/*   Updated: 2016/05/27 18:05:17 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		malloc_again(char **save)
{
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(*save))))
		return (0);
	ft_strcpy(tmp, *save);
	ft_bzero(*save, ft_strlen(*save));
	if (!(*save = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (0);
	ft_strcpy(*save, tmp);
	return (1);
}

int		fill_line(char **save, char **line, int ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ret > 0 && *save != NULL)
	{
		while ((*save)[i] != '\n' && (*save)[i])
		{
			(*line)[i] = (*save)[i];
			i++;
		}
		(*line)[i] = '\0';
		if ((*save)[0] == '\n')
		{
			while ((*save)[i])
				(*save)[j++] = (*save)[i++];
			(*save)[j] = '\0';
			return (1);
		}
		while ((*save)[i])
			(*save)[j++] = (*save)[i++];
		(*save)[j] = '\0';
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*save_line;
	int			ret;

	if (fd < 0 || !(((save_line = ft_strnew(BUFF_SIZE)) && save_line)))
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, *line, BUFF_SIZE)) > 0)
	{
		if (malloc_again(&save_line))
		{
			ft_strncat(save_line, *line, BUFF_SIZE);
			if (ft_memchr(*line, '\n', BUFF_SIZE))
				break ;
		}
		else
			return (-1);
	}
	if (ret > 0)
	{
		fill_line(&save_line, &(*line), ret);
		return (1);
	}
	if (ft_memcmp(*line, save_line, ft_strlen(*line)) == 0)
	{
		if (!(*line = ft_strdup("")))
			return (1);
		return (0);
	}
	return (1);
}
