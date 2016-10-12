/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:57:58 by ahoareau          #+#    #+#             */
/*   Updated: 2016/10/11 18:29:58 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		count(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			j++;	
			while (line[i] != ' ')
			{
				i++;
				if (line[i] == '\n' || line[i] == '\0')
					return (j);
			}
		}
		i++;
	}
	return(j);
}

//converti les colonnes en int
void	get_int(int i, t_env *e, char *line)
{
	int		n;
	int		j;
	int		z;

	n = 0;
	j = 0;
	z = 0;
	while (line[n] != '\0')
	{
		if (line[n] != ' ' && line[n] != '\0')
		{
			e->tab.tab[i][j] = line[n] - '0';
			n++;
			while (line[n] != ' ' && line[n] != '\0')
			{
				e->tab.tab[i][j] = e->tab.tab[i][j] * 10 + line[n] - '0';
				n++;
			}
			j++;
			z++;
		}
		if (line[n] == ' ')
			n++;
	}
}

void	tab_line(t_env *e, int fd)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		if (e->tab.i == 0)
			e->tab.j = count(line);
		e->tab.i++;
	}
}

//malloc la map
void	mall_tab(int fd, t_env *e)
{
	int		y;
	int		x;
	int		**tab;

	y = 0;
	x = 0;
	tab = NULL;
	e->tab.i = 0;
	tab_line(e, fd);	
	tab = (int **)malloc(sizeof(int *) * e->tab.i);		//malloc la taille de la map (nb ligne)
	if (tab == NULL)
	{
		ft_putendl("Probleme allocation memoire -> map.\n");
		exit(1);
	}
	while (y <= e->tab.i)
	{
		tab[y] = (int *)malloc(sizeof(int ) * e->tab.j);
		if (tab[y] == NULL)
			exit(1);
		y++;
	}
	e->tab.tab = tab;
}

t_env		*get_tab(char *str, t_env *e)
{
	int		fd;
	int		fd2;
	int		i;
	char	*line;

	i = 0;
	fd = open(str, O_RDONLY);
	fd2 = open(str, O_RDONLY);
	mall_tab(fd, e);
	close(fd);
	while (get_next_line(fd2, &line))
	{
		get_int(i, e, line);
		i++;
	}
	close(fd2);
	return (e);
}
