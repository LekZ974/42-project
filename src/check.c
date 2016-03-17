/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:58:29 by ggane             #+#    #+#             */
/*   Updated: 2016/03/18 00:42:24 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_system_call(char *file)
{
	int		fd;
	int		i;
	char	buf[BUF_SIZE];
	char	*str;

	i = 0;
	if ((fd = open(file, O_RDONLY)))
		while (read(fd, buf, BUF_SIZE))
			i++;
	close(fd);
	str = (char*)malloc(sizeof(char) * i);
	if (!str)
		return (1);
	fd = open(file, O_RDONLY);
	read(fd, str, i);
	close(fd);
	if (check_file(str))
		return (1);
	free(str);
	return (0);
}

int		check_file(char *file)
{
	int		i;
	int		j;
	char	*schema;

	i = 0;
	j = 0;
	if (!(schema = (char *)malloc(sizeof(char) * 21)))
		return (1);
	while (file[i])
	{
		if (j != 19)
			schema[j] = file[i];
		else
		{
			if (check_forme(schema))
				return (1);
			if (file[i + 1] != '\n' || file[i + 1] != '\0')
				return (1);
			if (file[i + 1] != '\0')
				i++;
			j = -1;
		}
		i++;
		j++;
	}
	free(schema);
	return (0);
}

int		check_forme(char *schema)
{
	int		i;
	int		j;
	int		sharp;

	i = 0;
	j = 0;
	sharp = 0;
	while (schema[i])
	{
		//if (check_line(schema))
			return (1);
		if (schema[i] == '#')
		{
			if (sharp == 1 && (j != 1 || j != 4 || j != 5))
				return (1);
			else if (sharp == 1)
			{
				sharp = 0;
				j = 0;
			}
			else
			{
				sharp = 1;
				j = 1;
			}
		}
		if (sharp == 1)
			j++;
		i++;
	}
	return (0);
}
