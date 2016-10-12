/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 13:02:47 by ahoareau          #+#    #+#             */
/*   Updated: 2016/10/07 16:58:01 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		key_funct(int keycode, t_env *e)
{
	printf("########## event key %d #########\n", keycode);
	if (keycode == 53)
	{
		free(e);
		exit(0);
	}
	if (keycode == 126 || keycode == 13)
	{
		erase(e);
		e->y_origin -= 10;
	}
	if (keycode == 125 || keycode == 1)
	{
		erase(e);
		e->y_origin += 10;
	}
	if (keycode == 123 || keycode == 0)
	{
		erase(e);
		e->x_origin -= 10;
	}
	if (keycode == 124 || keycode == 2)
	{
		erase(e);
		e->x_origin += 10;
	}
	if (keycode == 69 || keycode == 12)
	{
		erase(e);
		e->coef += 1;
	}
	if (e->coef != 0 && (keycode == 78 || keycode == 14))
	{
		erase(e);
		e->coef -= 1;
	}
	if (keycode == 67 || keycode == 17)
	{
		erase(e);
		e->amp -= 1;
	}
	if (keycode == 75 || keycode == 15)
	{
		erase(e);
		e->amp += 1;
	}
	if (keycode == 92 || keycode == 7)
	{
		erase(e);
		e->ang += 1;
	}
	if (keycode == 91 || keycode == 6)
	{
		erase(e);
		e->ang -= 1;
	}
	if (keycode == 81 || keycode == 50)
	{
		erase(e);
		disp_window(e);
	}
	draw(e);
	return (0);
}
