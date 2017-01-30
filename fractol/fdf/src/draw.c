/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:26:18 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/28 15:29:35 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		draw_line(t_env *e, t_point start, t_point end, t_tab *tab)
{
	int		x;
	int		y;

	x = end.x - start.x;
	y = end.y - start.y;
	x = ft_abs(x);
	y = ft_abs(y);
	if (x > y)
	{
		if (start.x < end.x)
			pixel_put1(e, start, end, tab);
		else if (start.x > end.x)
			pixel_put1(e, end, start, tab);
	}
	else
	{
		if (start.y < end.y)
			pixel_put2(e, start, end, tab);
		else if (start.y > end.y)
			pixel_put2(e, end, start, tab);
	}
}

void		draw_vert(t_env *e, t_tab *tab)
{
	int		x;
	int		y;

	y = 0;
	while (y < tab->ymax - 1)
	{
		x = 0;
		while (x < tab->xmax - 1)
		{
			tab->z1 = tab->input[y][x];
			tab->z2 = tab->input[y][x + 1];
			draw_line(e, tab->grid[y][x], tab->grid[y][x + 1], tab);
			x++;
		}
		tab->z1 = tab->input[y][tab->xmax - 1];
		tab->z2 = tab->input[y + 1][tab->xmax - 1];
		draw_line(e, tab->grid[y][tab->xmax - 1], \
				tab->grid[y + 1][tab->xmax - 1], tab);
		y++;
	}
}

void		draw_hori(t_env *e, t_tab *tab)
{
	int		x;
	int		y;

	x = 0;
	while (x < tab->xmax - 1)
	{
		y = 0;
		while (y < tab->ymax - 1)
		{
			tab->z1 = tab->input[y][x];
			tab->z2 = tab->input[y + 1][x];
			draw_line(e, tab->grid[y][x], tab->grid[y + 1][x], tab);
			y++;
		}
		tab->z1 = tab->input[tab->ymax - 1][x];
		tab->z2 = tab->input[tab->ymax - 1][x + 1];
		draw_line(e, tab->grid[tab->ymax - 1][x], \
				tab->grid[tab->ymax - 1][x + 1], tab);
		x++;
	}
}

void		draw(t_env *e, t_tab *tab)
{
	draw_vert(e, tab);
	draw_hori(e, tab);
	display_aff(e, tab);
}
