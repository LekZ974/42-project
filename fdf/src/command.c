/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 13:02:47 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/17 10:15:30 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		key_funct(int keycode, t_env *e)
{
	ft_erase(e);
	if (keycode == 53)
		ft_quit(e);
	if (keycode == 126 || keycode == 13)
		e->y_origin += 10;
	if (keycode == 125 || keycode == 1)
		e->y_origin -= 10;
	if (keycode == 123 || keycode == 0)
		e->x_origin += 10;
	if (keycode == 124 || keycode == 2)
		e->x_origin -= 10;
	if (keycode == 69 || keycode == 12)
	{
		e->coef += 1;
		e->x_origin -= 115;
		e->y_origin -= 55;
	}
	key_funct2(keycode, e);
	return (0);
}

int		key_funct2(int keycode, t_env *e)
{
	if (e->coef != 1 && (keycode == 78 || keycode == 14))
	{
		e->coef -= 1;
		e->x_origin += 115;
		e->y_origin += 55;
	}
	if (keycode == 67 || keycode == 17)
		e->amp -= 1;
	if (keycode == 75 || keycode == 15)
		e->amp += 1;
	if (keycode == 81 || keycode == 50)
		disp_window(e);
	if (keycode == 76)
		display_param(e);
	draw(e);
	return (0);
}

int		ft_quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}
