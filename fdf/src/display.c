/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 13:41:19 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/15 14:55:21 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	disp_window(t_env *e)
{
	e->y_origin = 100;
	e->x_origin = 100;
	e->coef = 10;
	e->amp = 0;
}

void	disp_limit(t_env *e)
{
	if (e->coord.x1 > WIDTH && e->coord.x2 > WIDTH)
	{
		e->coord.x1 = WIDTH;
		e->coord.x2 = WIDTH;
	}
	if (e->coord.y1 > HEIGHT && e->coord.y2 > HEIGHT)
	{
		e->coord.y1 = HEIGHT;
		e->coord.y2 = HEIGHT;
	}
	if (e->coord.x1 < 0 && e->coord.x2 < 0)
	{
		e->coord.x1 = 0;
		e->coord.x2 = 0;
	}
	if (e->coord.y1 < 0 && e->coord.y2 < 0)
	{
		e->coord.y1 = 0;
		e->coord.y2 = 0;
	}
}

void	display_aff(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 700, 20, 0xFFFFFF, "QUITTER = ECHAP      MENU = 0");
	mlx_string_put(e->mlx, e->win, 700, 50, 0xFFFFFF, "Amplitude:");
	mlx_string_put(e->mlx, e->win, 800, 50, 0xFFFFFF, ft_itoa(-e->amp));
	mlx_string_put(e->mlx, e->win, 700, 80, 0xFFFFFF, "Coordonnees:");
	mlx_string_put(e->mlx, e->win, 850, 80, 0xFFFFFF, ft_itoa(e->x_origin));
	mlx_string_put(e->mlx, e->win, 900, 80, 0xFFFFFF, ft_itoa(e->y_origin));
	mlx_string_put(e->mlx, e->win, 700, 110, 0xFFFFFF, "Zoom: X");
	mlx_string_put(e->mlx, e->win, 850, 110, 0xFFFFFF, ft_itoa(e->coef));
}

void	display_param(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, HEIGHT - 70, 0xFFFFFF, "Deplacement : WASD / fleches");
	mlx_string_put(e->mlx, e->win, 20, HEIGHT - 50, 0xFFFFFF, "ZOOM : +/Q  DEZOOM : -/E");
	mlx_string_put(e->mlx, e->win, 400, HEIGHT - 70, 0xFFFFFF, "Amplitude positive: */R   Amplitude negative : //T");
	mlx_string_put(e->mlx, e->win, 400, HEIGHT - 50, 0xFFFFFF, "Reinitialiser : = ");
}

void	ft_erase(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
}
