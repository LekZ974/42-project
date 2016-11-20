/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:41:23 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/17 10:03:33 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	pixel_put1(t_env *e)
{
	int		x;

	x = e->coord.x1;
	while (++x <= e->coord.x2)
		mlx_pixel_put(e->mlx, e->win, x, e->coord.y1 +\
				((e->coord.y2 - e->coord.y1) * (x - e->coord.x1)) /\
				(e->coord.x2 - e->coord.x1), ft_color(e));
}

void	pixel_put2(t_env *e)
{
	int		x;

	x = e->coord.x2;
	while (++x <= e->coord.x1)
		mlx_pixel_put(e->mlx, e->win, x, e->coord.y2 +\
				((e->coord.y1 - e->coord.y2) * (x - e->coord.x2)) /\
				(e->coord.x1 - e->coord.x2), ft_color(e));
}

void	pixel_put3(t_env *e)
{
	int		y;

	y = e->coord.y1;
	while (++y <= e->coord.y2)
		mlx_pixel_put(e->mlx, e->win, e->coord.x1 +\
				((e->coord.x2 - e->coord.x1) * (y - e->coord.y1)) /\
				(e->coord.y2 - e->coord.y1), y, ft_color(e));
}

void	pixel_put4(t_env *e)
{
	int		y;

	y = e->coord.y2;
	while (++y <= e->coord.y1)
		mlx_pixel_put(e->mlx, e->win, e->coord.x2 +\
				((e->coord.x1 - e->coord.x2) * (y - e->coord.y2)) /\
				(e->coord.y1 - e->coord.y2), y, ft_color(e));
}
