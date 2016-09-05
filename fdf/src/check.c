/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 14:22:03 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/04 12:32:17 by ahoareau         ###   ########.fr       */
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
		return (1);
	}
	close(fd);
	return (0);
}

int		check_file(char *str)					//check si data est composer de caractere entre 0 et 9
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '\n'))
			return (1);
		i++;
	}
	return (0);
}
