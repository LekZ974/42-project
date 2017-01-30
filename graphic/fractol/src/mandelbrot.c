/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracdelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:17:04 by ahoareau          #+#    #+#             */
/*   Updated: 2016/12/19 13:26:44 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			ft_get_color(int z, t_color pix_col)
{
	int		color;

	z = sin(z) * 100;
	if (z < 0)
		color = pix_col.color_def;
	if (z >= 0 && z < 10)
		color = pix_col.color00;
	if (z >= 10 && z < 20)
		color = pix_col.color01;
	if (z >= 20 && z < 30)
		color = pix_col.color02;
	if (z >= 30 && z < 40)
		color = pix_col.color03;
	if (z >= 40 && z < 50)
		color = pix_col.color04;
	if (z >= 50 && z < 60)
		color = pix_col.color05;
	if (z >= 60 && z < 70)
		color = pix_col.color06;
	if (z >= 70 && z < 80)
		color = pix_col.color07;
	if (z >= 80 && z < 90)
		color = pix_col.color08;
	if (z >=90)
		color = pix_col.color09;
	return (color);
}

void		ft_draw_pxl_img(t_env *e, t_point *pt, int color)
{
	int		i;

	i = (int)pt->x * 4 + (int)pt->y * e->sizeline;
	e->pxl_img[i] = color;
	e->pxl_img[++i] = color >> 8;
	e->pxl_img[++i] = color >> 16;
}

void		ft_mandelbrot(t_env *e, t_frac *frac, t_point *pt)
{
	int		color;

/*	ft_putnbr(pt->x);
	ft_putchar(' ');
	ft_putnbr(pt->y);
	ft_putchar(' ');
	ft_putstr("x1 :");
	ft_putnbr(frac->x1);
	ft_putchar(' ');
	ft_putstr("y1 :");
	ft_putnbr(frac->y1);
	ft_putchar(' ');
	ft_putstr("zoom :");
	ft_putnbr(frac->zoom);
	ft_putchar(' ');
	ft_putstr("tmp :");
	ft_putnbr(frac->tmp);
	ft_putchar(' ');
	ft_putstr("zr :");
	ft_putnbr(frac->z.r);
	ft_putchar(' ');
	ft_putstr("it :");
	ft_putnbr(frac->it);
	ft_putchar(' ');
	ft_putstr("itmax :");
	ft_putnbr(frac->itmax);
	ft_putchar('\n');*/
	frac->c.r = pt->x / frac->zoom + frac->x1;
	frac->c.i = pt->y / frac->zoom + frac->y1;
	frac->tmp = frac->z.r;
	while ((frac->z.r * frac->z.r - frac->z.i * frac->z.i) < 4 && frac->it < frac->itmax)
	{
		frac->z.r = frac->z.r * frac->z.r - frac->z.i * frac->z.i + frac->c.r;
		frac->z.i = 2 * frac->z.i * frac->tmp + frac->c.i;
		frac->it = frac->it + 1;
	}
	if (frac->it == frac->itmax)
		color = ft_get_color(-1, *(e->color));
	else
		color = ft_get_color((frac->it * frac->it) * 0.1, *(e->color));
	ft_draw_pxl_img(e, pt, color);
}

void		ft_draw_fractal(t_env *e, t_frac *frac)
{
	t_point	pt;

	pt.y = 0;
	while (pt.y < HEIGHT)
	{
		pt.x = 0;
		while (pt.x < WIDTH)
		{
			ft_mandelbrot(e, frac, &pt);
			pt.x++;
		}
		pt.y++;
	}
	ft_putendl("draw fractal");
}

/*void		*draw(t_env *e, t_frac *frac)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->pxl_img = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	ft_draw_fractal(e, frac, frac->func);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->win);
	return (frac);
}*/
