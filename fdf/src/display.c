/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 13:41:19 by ahoareau          #+#    #+#             */
/*   Updated: 2016/10/07 15:45:53 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	disp_window(t_env *e)
{
	e->y_origin = 300 ;
	e->x_origin = 400 ;
	e->coef = 10;
	e->amp = 0;
	e->ang = 1;
}

int		disp_point_x(t_env *e, int coord)
{
	coord = e->x_origin + coord * e->coef;
	return (coord);
}

int		disp_point_y(t_env *e, int coord)
{
	coord = (e->y_origin + coord * e->coef + e->tab.tab[e->coord.y][e->coord.x] * e->amp);
	return (coord);
}

void	erase(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
}
