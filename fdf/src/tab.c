/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:24:29 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/28 17:26:26 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		mall_tab(t_tab *tab, char *file)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open(file, O_RDONLY);
	tab->input = (int **)malloc(sizeof(int *) * tab->ymax);
	i = 0;
	while (i < tab->ymax)
	{
		get_next_line(fd, &line);
		tab->input[i] = (int *)malloc(sizeof(int) * tab->xmax);
		j = 0;
		while (j < tab->xmax)
		{
			tab->input[i][j] = (int)ft_strtol(line, &line, 10);
			j++;
			while (*line && *line == ' ')
				line++;
		}
		i++;
	}
	close(fd);
}

int			get_width(char *line)
{
	char	**split;
	int		width;

	width = 0;
	split = ft_strsplit(line, ' ');
	while (split[width])
		width++;
	return (width);
}

void		get_size(t_tab *tab, char *line, int fd)
{
	while (get_next_line(fd, &line))
	{
		if (tab->ymax == 0)
			tab->xmax = get_width(line);
		if (valid_file(tab, line) == 1)
		{
			close(fd);
			ft_putendl("invalid map: verify file [source].fdf \n");
			exit(1);
		}
		tab->ymax++;
	}
}

t_tab		*init_tab(void)
{
	t_tab	*tab;

	tab = (t_tab *)malloc(sizeof(t_tab));
	tab->xmax = 0;
	tab->ymax = 0;
	tab->rotx = 1;
	tab->roty = 1;
	data_handing(tab);
	tab->input = NULL;
	tab->grid = NULL;
	return (tab);
}

void		get_tab(char *file, t_tab *tab)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = NULL;
	get_size(tab, line, fd);
	mall_tab(tab, file);
	get_min_max(tab);
	close(fd);
}
