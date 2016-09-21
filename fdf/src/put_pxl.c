/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:41:23 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/21 15:29:11 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	pixel_put(t_env *env, int x, int y)
{
	int		pos;

	if ( x >= 0 && x < WIDTH && y >= 0 && y < LENGTH)
	{
		pos = (x * env->img.bpp / 8) + (y * env->img.sl);
	}

}

void	draw_r_h(t_env *env)
{
	int		x;

	x = env->p1.x;
	ft_putnbr(x);
	ft_putchar('-');
	ft_putnbr(env->p2.x);
	ft_putchar('-');
	ft_putnbr(env->p1.x);
	ft_putchar('\n');
	while (x <= env->p2.x)
	{
		pixel_put(env, x, env->p1.y + ((env->p2.y - env->p1.y) * (x - env->p1.x)) / (env->p2.x - env->p1.x));
	}
	ft_putstr("DRAW1\n");
}

void	draw_l_h(t_env *env)
{
	int		x;

	x = env->p2.x;
	while (x <= env->p1.x)
	{
		pixel_put(env, x, env->p2.y + ((env->p1.y - env->p2.y) * (x - env->p2.x)) / (env->p1.x - env->p2.x));
	}
	ft_putstr("DRAW2\n");
}

void	draw_d_v(t_env *env)
{
	int		y;

	y = env->p1.y;
	while (y <= env->p2.y)
	{
		pixel_put(env, env->p2.x + ((env->p1.x - env->p2.x) * (y - env->p2.y)) / (env->p1.y - env->p2.y), y);
	}
	ft_putstr("DRAW3\n");
}

void	draw_u_v(t_env *env)
{
	int		y;

	y = env->p2.y;
	while (y <= env->p1.y)
	{
		pixel_put(env, env->p1.x + ((env->p2.x - env->p1.x) * (y - env->p1.y)) / (env->p2.y - env->p1.y), y);
	}
	ft_putstr("DRAW4\n");
}

void	draw_lign(t_env *env)
{
	ft_putstr("ALORS?\n");
	if (env->p1.x <= env->p2.x && (env->p2.x - env->p1.x) >= abs(env->p2.y - env->p1.y))
				draw_r_h(env);
		else if (env->p2.x <= env->p1.x && (env->p1.x - env->p2.x) >= abs(env->p1.y - env->p2.y))
				draw_l_h(env);
		else if (env->p2.y <= env->p1.y && (env->p1.y - env->p2.y) >= abs(env->p1.x - env->p2.x))
				draw_u_v(env);
		else if (env->p1.y <= env->p2.y && (env->p2.y - env->p1.y) >= abs(env->p2.x - env->p1.x))
				draw_d_v(env);
}
//Trouver ou sa segfault
//si pas bon revenir ancien git
//
//segfault ds les deplacements avec les fleche, comprendre comment sauvegarder une data ds la structure
