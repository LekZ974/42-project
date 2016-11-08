/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 13:02:47 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/06 17:59:08 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		key_funct(int keycode, t_env *e)
{
	erase(e);
	if (keycode == 53)
	{
		free(e);
		exit(0);
	}
	if (keycode == 126 || keycode == 13)
		e->y_origin -= 10;
	if (keycode == 125 || keycode == 1)
		e->y_origin += 10;
	if (keycode == 123 || keycode == 0)
		e->x_origin -= 10;
	if (keycode == 124 || keycode == 2)
		e->x_origin += 10;
	if (keycode == 69 || keycode == 12)
	{
		e->coef += 1;
		e->x_origin -= 5;
		e->y_origin -= 5;
	}
	key_funct2(keycode, e);
	return (0);
}

int		key_funct2(int keycode, t_env *e)
{
	if (e->coef != 1 && (keycode == 78 || keycode == 14))
	{
		e->coef -= 1;
		e->x_origin += 5;
		e->y_origin += 5;
	}
	if (keycode == 67 || keycode == 17)
		e->amp -= 1;
	if (keycode == 75 || keycode == 15)
		e->amp += 1;
	if (keycode == 92 || keycode == 7)
		e->ang += 1;
	if (keycode == 91 || keycode == 6)
		e->ang -= 1;
	if (keycode == 81 || keycode == 50)
		disp_window(e);
	if (keycode == 82)
		display_param(e);
	draw(e);
	ft_putendl("keyfunc");
	return (0);
}
