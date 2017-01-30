/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:30:21 by ahoareau          #+#    #+#             */
/*   Updated: 2016/12/15 14:50:30 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		color_init(t_env *e)
{
	if (!(e->color = (t_color *)malloc(sizeof(t_color))))
		ft_malloc_error();
	e->color[0] = (t_color){0x000000, 0x090132, 0x04044A, 0x000865, 0x0B2C89, 0x1752B0, 0x88B4E3, 0xD4EBFB, 0xF1EABE, 0xF6CB5A, 0xFFAA00};
}

t_env		*init_env(void)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fractol 42");
	e->img = NULL;
	e->pxl_img = NULL;
	e->bpp = 0;
	e->sizeline = 0;
	e->endian = 0;
	color_init(e);
	return (e);
}
