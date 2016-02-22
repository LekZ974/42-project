/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:27:50 by ahoareau          #+#    #+#             */
/*   Updated: 2016/02/22 17:39:58 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		open_close(char *file)
{
	int		fd;
	int		index;
	int		nbT;
	int		res;
	char	buf[BUF_SIZE];

	index = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			index++;
	}
	nbT = (index / 5) + 1;
	res = ft_sqrt(nbT * 4);
	display_square(res);
	printf("index : %d, nbT : %d\n, racine nbT : %d", index, nbT, ft_sqrt(nbT * 4));
	close(fd);
	return (0);
}

int		ft_sqrt(int nb)
{
	int		count;

	count = 0;
	while (count * count < nb)
		count++;
	if (count * count == nb)
		return (count);
	else
		return (ft_sqrt(nb + 1));
	return (0);
}
