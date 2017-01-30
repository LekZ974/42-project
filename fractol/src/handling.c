/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:32:28 by ahoareau          #+#    #+#             */
/*   Updated: 2016/12/19 14:00:38 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			key_funct(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->e->mlx, data->e->win);
		exit(1);
	}
	data = NULL;
	return (0);
}

int			expose_hook(t_env *e, t_data data)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->pxl_img = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	ft_draw_fractal(e, data.frac);
//	ft_user_interface(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_putendl("expose hook");
	return (0);
}

void		handling(t_env *e, t_frac *frac)
{
	t_data	data;

	data.e = e;
	data.frac = frac;
	ft_putnbr(frac->itmax);
	ft_putchar('\n');
	mlx_expose_hook(e->win, expose_hook, &data);
	mlx_hook(e->win, 2, (1L < 10), key_funct, &data);
	mlx_loop(e->mlx);
	ft_putendl("handling");
}
