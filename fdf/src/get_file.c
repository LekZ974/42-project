/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:57:58 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/06 15:53:18 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int			count(char *line)
{
	char	**split;
	int		j;

	j = -1;
	split = ft_strsplit(line, ' ');
	while (split[++j])
		;
	return (j);
}

void		get_int(int i, t_env *e, char *line)
{
	int		j;
	char	**split;

	j = -1;
	split = ft_strsplit(line, ' ');
	while (split[++j])
	{
		e->tab.tab[i][j] = ft_atoi(split[j]);
		ft_putnbr(e->tab.tab[i][j]);
	}
}

void		tab_line(t_env *e, int fd)
{
	char	*line;

	e->tab.i = 0;
	while (get_next_line(fd, &line))
	{
		if (e->tab.i == 0)
			e->tab.j = count(line);
		e->tab.i++;
	}
	ft_putnbr(e->tab.i);
	ft_putchar('\n');
	ft_putnbr(e->tab.j);
	ft_putchar('\n');
}

void		mall_tab(int fd, t_env *e)
{
	int		y;
	int		**tab;

	y = -1;
	tab = NULL;
	tab_line(e, fd);
	tab = ft_memalloc((sizeof(int *)) * e->tab.i);
	if (tab == NULL)
		exit(1);
	while (++y <= e->tab.i)
	{
		tab[y] = ft_memalloc((sizeof(int)) * e->tab.j);
		if (tab[y] == NULL)
			exit(1);
	}
	e->tab.tab = tab;
}

t_env		*get_tab(t_env *e)
{
	int		fd;
	int		fd2;
	int		i;
	char	*line;

	i = -1;
	fd = open(e->file, O_RDONLY);
	fd2 = open(e->file, O_RDONLY);
	mall_tab(fd, e);
	close(fd);
	while (get_next_line(fd2, &line))
		get_int(++i, e, line);
	close(fd2);
	return (e);
}
