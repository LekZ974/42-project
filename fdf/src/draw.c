/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:51:04 by ahoareau          #+#    #+#             */
/*   Updated: 2016/10/12 17:13:56 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_env *e, int x1, int x2, int y1, int y2)
{
	x1 = disp_point_x(e, x1);
	x2 = disp_point_x(e, x2);
	y1 = disp_point_y(e, y1);
	y2 = disp_point_y(e, y2);
	if (x1 <= x2 && (x2 - x1) > 0)
		pixel_put_r(e, x1, x2, y1, y2);
	else if (x2 <= x1 && (x1 - x2) > 0)
		pixel_put_r(e, x2, x1, y2, y1);
	else if (y2 <= y1 && (y1 - y2) > 0)
		pixel_put_u(e, x1, x2, y1, y2);
	else if (y1 <= y2 && (y2 - y1) > 0)
		pixel_put_u(e, x2, x1,y2, y1);
}

void	draw_pos_h(t_env *e, int x, int y)
{
	int		x2;
	int		y2;

	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x == e->tab.j - 1 + e->tab.itmp)
	{	
		x2 = x;
		y2 = y;
	}
	else
	{
		x2 = e->coord.coord[e->coord.y][e->coord.x + 1][0];
		y2 = e->coord.coord[e->coord.y][e->coord.x + 1][1];
	}
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x2);
	ft_putchar(' ');
	ft_putnbr(y2);
	ft_putchar('\n');
	draw_line(e, x, x2, y, y2);
}

void	draw_pos_v(t_env *e, int x, int y)
{
	int		x2;
	int		y2;

	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (y == e->tab.i - 1)
	{
		x2 = x;
		y2 = y;
	}
	else
	{
		x2 = e->coord.coord[e->coord.y + 1][e->coord.x][0];
		y2 = e->coord.coord[e->coord.y + 1][e->coord.x][1];
	}
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x2);
	ft_putchar(' ');
	ft_putnbr(y2);
	ft_putchar('\n');
	draw_line(e, x, x2, y, y2);
}

void	draw(t_env *e)
{
	e->coord.x = 0;
	e->coord.y = 0;
	get_coord(e, e->coord.x, e->coord.y);
	e->tab.itmp = 0;
	while (e->coord.y < e->tab.i)
	{
		e->coord.x = 0;
		ft_putstr("#############\n");
		while (e->coord.x < e->tab.j)
		{
			ft_putchar('\n');
			draw_pos_h(e, e->coord.coord[e->coord.y][e->coord.x][0], e->coord.coord[e->coord.y][e->coord.x][1]);
			draw_pos_v(e, e->coord.coord[e->coord.y][e->coord.x][0], e->coord.coord[e->coord.y][e->coord.x][1]);
			e->coord.x++;
		}
		ft_putstr("\n#############\n");
		e->coord.y++;
		e->tab.itmp++;
	}
}

//y2 depasse les limites fixer a resoudre (a reverifier)
//faire ligne verticale
//pivot a peu pres bon
