/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:43:55 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/28 18:20:56 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			check_data(char *line)
{
	int		j;

	j = 0;
	while (ft_isdigit(line[j]) == 1 || line[j] == '-' || line[j] == ' ')
	{
		j++;
		if (line[j] == '\0' || line[j] == '\n')
			return (0);
	}
	return (1);
}

int			valid_file(t_tab *tab, char *line)
{
	if (tab->xmax != get_width(line))
		return (1);
	if (check_data(line) == 1)
		return (1);
	return (0);
}

int			exist_file(char *buf, int fd)
{
	if (read(fd, buf, BUFF_SIZE) == -1)
		return (1);
	return (0);
}

int			get_file_ext(const char *file)
{
	char	*dot;
	char	*ext;

	ext = ".fdf";
	dot = ft_strrchr(file, '.');
	if (ft_strcmp(dot, ext) == 0)
		return (0);
	return (1);
}

int			check(char *file)
{
	int		fd;
	char	buf[BUFF_SIZE];

	fd = open(file, O_RDONLY);
	if (exist_file(buf, fd) == 1)
	{
		close(fd);
		return (1);
	}
	if (get_file_ext(file) == 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
