/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:27:08 by ahoareau          #+#    #+#             */
/*   Updated: 2016/10/12 15:28:56 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mall_coord(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	e->coord.coord = (int ***)malloc(sizeof(int **) * e->tab.i);
	while (i <= e->tab.i)
	{
		e->coord.coord[i] = (int **)malloc(sizeof(int *) * e->tab.j);
		j = 0;
		while (j <= e->tab.j)
		{
			e->coord.coord[i][j] = (int *)malloc(sizeof(int) * 2);
			j++;
		}
		i++;
	}
}

void	get_coord(t_env *e, int x, int y)
{
	mall_coord(e);
	y = 0;
	e->tab.itmp = 0;
	while (y < e->tab.i)
	{
		x = 0;
		while (x < e->tab.j)
		{
			e->coord.coord[y][x][0] = x + e->tab.itmp;
			e->coord.coord[y][x][1] = y;
			ft_putstr("-------------\n");
			ft_putnbr(x);
			ft_putchar(' ');
			ft_putnbr(y);
			ft_putchar(' ');
			ft_putnbr(e->coord.coord[y][x][0]);
			ft_putchar(' ');
			ft_putnbr(e->coord.coord[y][x][1]);
			ft_putstr("\n-------------\n");
			x++;
		}
		y++;
		e->tab.itmp++;
	}
}
