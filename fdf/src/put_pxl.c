/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:41:23 by ahoareau          #+#    #+#             */
/*   Updated: 2016/10/11 16:40:08 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	pixel_put_r(t_env *e, int x1, int x2, int y1, int y2)
{
	int		x;

	x = x1;
	while (++x <= x2)
		mlx_pixel_put(e->mlx, e->win, x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1), 0xFFFFFF);
}

/*void	pixel_put_l(t_env *e, int x1, int x2, int y1, int y2)
{
	int		x;

	x = x2;
	while (++x <= x1)
		mlx_pixel_put(e->mlx, e->win, x, y2 + ((y1 - y2) * (x - x2)) / (x1 - x2), 0xFFFFFF);
}
*/
void	pixel_put_u(t_env *e, int x1, int x2, int y1, int y2)
{
	int		y;

	y = y1;
	while (++y <= y2)
		mlx_pixel_put(e->mlx, e->win, x1 + ((x2 - x1) * (y - y1)) / (y2 - y1), y, 0xFF88FF);
}

/*void	pixel_put_d(t_env *e, int x1, int x2, int y1, int y2)
{
	int		y;

	y = y2;
	while (++y <= y1)
		mlx_pixel_put(e->mlx, e->win, x2 + ((x1 - x2) * (y - y2)) / (y1 - y2), y, 0xFFFFFF);
}*/
