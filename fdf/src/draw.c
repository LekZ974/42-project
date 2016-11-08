/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:51:04 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/06 17:26:33 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	join(t_env *e)
{
	int		x;
	int		y;

	x = e->coord.x1 - e->coord.x2;
	y = e->coord.y1 - e->coord.y2;
	x = ft_abs(x);
	y = ft_abs(y);
	disp_limit(e);
	if (x > y)
	{
		if (e->coord.x1 < e->coord.x2)
			pixel_put1(e);
		else if (e->coord.x1 > e->coord.x2)
			pixel_put2(e);
	}
	else
	{
		if (e->coord.y1 < e->coord.y2)
			pixel_put3(e);
		else if (e->coord.y1 > e->coord.y2)
			pixel_put4(e);
	}
}

void	coord_h(t_env *e, int x, int y)
{
	e->coord.x1 = e->coord.coord[y][x][0] + e->x_origin;
	e->coord.y1 = e->coord.coord[y][x][1] + e->y_origin;
	if (x != e->tab.j - 1)
	{
		e->coord.x2 = e->coord.coord[y][x + 1][0] + e->x_origin;
		e->coord.y2 = e->coord.coord[y][x + 1][1] + e->y_origin;
	}
	else
	{
		e->coord.x2 = e->coord.coord[y][x][0] + e->x_origin;
		e->coord.y2 = e->coord.coord[y][x][1] + e->y_origin;
	}
	join(e);
}

void	coord_v(t_env *e, int x, int y)
{
	e->coord.x1 = e->coord.coord[y][x][0] + e->x_origin;
	e->coord.y1 = e->coord.coord[y][x][1] + e->y_origin;
	if (y != e->tab.i - 1)
	{
		e->coord.x2 = e->coord.coord[y + 1][x][0] + e->x_origin;
		e->coord.y2 = e->coord.coord[y + 1][x][1] + e->y_origin;
	}
	else
	{
		e->coord.x2 = e->coord.coord[y][x][0] + e->x_origin;
		e->coord.y2 = e->coord.coord[y][x][1] + e->y_origin;
	}
	join(e);
}

void	draw_pos(t_env *e, int x, int y)
{
	e->level = e->tab.tab[y][x] * e->amp;
	coord_h(e, x, y);
	coord_v(e, x, y);
}

void	draw(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	e->tab.itmp = 0;
	get_coord(e);
	while (y < e->tab.i)
	{
		x = 0;
		while (x < e->tab.j)
		{
			if (x == e->tab.j - 1 && y == e->tab.i - 1)
				return ;
			draw_pos(e, x, y);
			x++;
		}
		y++;
		e->tab.itmp++;
	}
}
