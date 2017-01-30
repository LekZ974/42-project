/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:00:22 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/28 16:16:28 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		parse(t_tab *tab)
{
	int		x;
	int		y;

	tab->grid = (t_point **)malloc(sizeof(t_point *) * tab->ymax);
	y = 0;
	while (y < tab->ymax)
	{
		tab->grid[y] = (t_point *)malloc(sizeof(t_point) * tab->xmax);
		x = 0;
		while (x < tab->xmax)
		{
			tab->grid[y][x].x = ((x - y) * tab->rotx) * tab->coef + INIT_X + \
								tab->pos.x;
			tab->grid[y][x].y = ((x + y) * tab->roty) * tab->coef + INIT_Y - \
								(tab->amp * tab->input[y][x]) + tab->pos.y;
			x++;
		}
		y++;
	}
}
