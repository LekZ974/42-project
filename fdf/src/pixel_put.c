/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:20:05 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/28 16:13:16 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		pixel_put1(t_env *e, t_point start, t_point end, t_tab *tab)
{
	int		x;

	x = start.x;
	while (++x <= end.x)
		mlx_pixel_put(e->mlx, e->win, x, start.y + ((end.y - start.y) * \
					(x - start.x)) / (end.x - start.x), ft_color(tab));
}

void		pixel_put2(t_env *e, t_point start, t_point end, t_tab *tab)
{
	int		y;

	y = start.y;
	while (++y <= end.y)
		mlx_pixel_put(e->mlx, e->win, start.x + ((end.x - start.x) * \
					(y - start.y)) / (end.y - start.y), y, ft_color(tab));
}

void		display_aff(t_env *e, t_tab *tab)
{
	mlx_string_put(e->mlx, e->win, 700, 20, 0xFFFFFF, \
			"QUITTER = [ECHAP]      MENU = [ENTER]");
	mlx_string_put(e->mlx, e->win, 700, 50, 0xFFFFFF, "Amplitude:");
	mlx_string_put(e->mlx, e->win, 800, 50, 0xFFFFFF, ft_itoa(tab->amp));
	mlx_string_put(e->mlx, e->win, 700, 80, 0xFFFFFF, "Coordonnees:");
	mlx_string_put(e->mlx, e->win, 850, 80, 0xFFFFFF, ft_itoa(tab->pos.x));
	mlx_string_put(e->mlx, e->win, 900, 80, 0xFFFFFF, ft_itoa(tab->pos.y));
	mlx_string_put(e->mlx, e->win, 700, 110, 0xFFFFFF, "Zoom: X");
	mlx_string_put(e->mlx, e->win, 850, 110, 0xFFFFFF, ft_itoa(tab->coef));
}

void		display_param(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, HEIGHT - 80, 0xFFFFFF, \
			"Deplacement : [WASD | fleches]");
	mlx_string_put(e->mlx, e->win, 20, HEIGHT - 60, 0xFFFFFF, \
			"ZOOM : [+ | Q]  DEZOOM : [- | E]");
	mlx_string_put(e->mlx, e->win, 400, HEIGHT - 80, 0xFFFFFF, \
			"Amplitude positive: [* | T]   Amplitude negative : [/ | R]");
	mlx_string_put(e->mlx, e->win, 400, HEIGHT - 60, 0xFFFFFF, \
			"Rotation sur X: [1]   				Rotation sur Y : [2]");
	mlx_string_put(e->mlx, e->win, 20, HEIGHT - 40, 0xFFFFFF, \
			"Reinitialiser : [CLEAR] ");
}
