/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:40:04 by ahoareau          #+#    #+#             */
/*   Updated: 2016/02/23 16:54:04 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		who_is_min(int *tab)
{
	int	min;
	int	i;

	min = 0;
	i = 0;
	while (i <= min)
	{
		min = tab[i];
		i++;
	}
	return (min);
}

/*int		read_piece(t_list *list, int nbT, char *file)
{
	char	buf[BUF_SIZE];
	int		fd;
	int		point;
	int		i;
	int		j;
	int		k;
	int		tab[4];
	int		min;

	i = 0;
	j = 0;
	k = 0;
	point = 0;
	fd = open(file, O_RDONLY);
	while (nbT > 0)
	{
		while (read (fd, buf, 1))
		{
			if (buf[0] == '.')
				point++;
			else if (j == 4)
			{
				j = 0;
				tab[i] = point;
				point = 0;
				i++;
			}
			if (k == 21)
				break ;
			k++;
			j++;
		}
		k = 0;
		nbT--;
		min = who_is_min(&tab);
		close(fd);
		fd = open(file, O_RDONLY);
	}
	return (0);
}*/


