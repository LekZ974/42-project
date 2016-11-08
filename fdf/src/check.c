/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 14:22:03 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/05 16:00:01 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	int		j;
	char	**split;

	i = 0;
	j = 0;
	split = ft_strsplit(str, ' ');
	while (split[i])
	{
		j = 0;
		while (ft_isalnum(split[i][j]) == 1 || split[i][j] == '-')
		{
			j++;
			if (split[i][j] == '\0')
				return (0);
		}
		i++;
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
