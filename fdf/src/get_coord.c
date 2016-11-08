/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:27:08 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/05 16:09:20 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mall_coord(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	e->coord.coord = ft_memalloc((sizeof(int **)) * e->tab.i);
	if (e->coord.coord == NULL)
		exit(1);
	while (++y <= e->tab.i)
	{
		e->coord.coord[y] = ft_memalloc((sizeof(int *)) * e->tab.j);
		if (e->coord.coord[y] == NULL)
			exit(1);
		x = -1;
		while (++x <= e->tab.j)
		{
			e->coord.coord[y][x] = ft_memalloc((sizeof(int)) * 2);
			if (e->coord.coord[y][x] == NULL)
				exit(1);
		}
	}
}

void	get_coord(t_env *e)
{
	int		x;
	int		y;

	mall_coord(e);
	y = -1;
	e->tab.itmp = 0;
	while (++y < e->tab.i)
	{
		x = -1;
		while (++x < e->tab.j)
		{
			e->coord.coord[y][x][0] = (x + e->tab.itmp) * e->coef;
			e->coord.coord[y][x][1] = y * e->coef + e->tab.tab[y][x] * e->amp;
		}
		e->tab.itmp++;
	}
}
