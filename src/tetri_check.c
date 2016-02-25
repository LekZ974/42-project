/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:40:04 by ahoareau          #+#    #+#             */
/*   Updated: 2016/02/25 12:55:48 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tlist		*add_tetriminos(char *file, t_tlist *list2)
{
	int		fd;
	int		i;
	int		j;
	int		k;
	int		l;
	int		tab[4];
	char	buf[BUF_SIZE];
	char	*new_buf;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buf, 1))
		i++;
	new_buf = malloc(sizeof(char) * i);
	fd = open(file, O_RDONLY);
	if (new_buf)
	{
		read(fd, new_buf, i);
		while (new_buf[j])
		{
			if (new_buf[j] == '#')
			{
				j++;
				while (new_buf[j] != '#')
				{
					tab[k] = l++;
					j++;
				}
				l = 0;
				k++;
				if (k == 4)
				{
					list2 = append_tetri(list2, tab);
					k = 0;
				}
			}
			j++;
		}
	}
	free(new_buf);
	close(fd);
	return (list2);
}

void	print_tetriminos(t_tlist *list)
{
	t_tetri		*tmp;
	int			i;
	int			k;
	int			j;
	int			l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	tmp = list->head;
	while (tmp)
	{
		while (k < 20)
		{
			if (i < 4 && tmp->p[j] != l)
				ft_putchar(' ');
			else if (tmp->p[j] == l)
			{
				ft_putchar('#');
				l = 0;
			}
			else if (i == 4)
			{
				ft_putchar('\n');
				i = 0;
			}
			else if (j == 3)
				j = 0;
			i++;
			l++;
			j++;
			k++;
		}
		tmp = tmp->next;
	}
}
