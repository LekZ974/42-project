/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:40:04 by ahoareau          #+#    #+#             */
/*   Updated: 2016/03/21 13:45:33 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_tetriminos(char *file, t_tlist *list2)
{
	int		fd;
	int		i;
	int		k;
	int		l;
	int		j;
	int		s;
	int		nb;
	char	letter;
	int		tab[3];
	char	buf[BUF_SIZE];
	char	*new_buf;

	i = 0;
	k = 0;
	l = 0;
	s = 0;
	j = 0;
	nb = 1;
	letter = 'A';
	fd = open(file, O_RDONLY);
	while (read(fd, buf, 1))
		i++;
	close(fd);
	fd = open(file, O_RDONLY);
	new_buf = malloc(sizeof(char) * i);
	read(fd, new_buf, i);
	close(fd);
	if (new_buf)
	{
		while (new_buf[j])
		{
			if (new_buf[j] == '#')
			{
				if (s == 1)
				{
					tab[k] = l;
					l = 0;
					k++;
				}
				++l;
				s = 1;
			}
			if (new_buf[j] != '#' && s == 1)
				l++;
			if (k == 3)
			{
				list2 = append_tetri(list2, tab, nb++, letter++);
				k = 0;
			}
			if (new_buf[j] == '\n' && new_buf[j + 1] == '\n')
			{
				l = 0;
				s = 0;
			}
			j++;
		}
	}
	free(new_buf);
}
