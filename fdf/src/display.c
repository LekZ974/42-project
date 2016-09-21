/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 13:41:19 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/21 14:09:23 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	disp_window(t_env *env)
{
	env->tab.cy = 300 % (env->tab.i * LENGTH);
	env->tab.cx = 400 % (env->tab.j * WIDTH);
//	ft_putnbr(env->tab.cx);
//	ft_putchar('\n');
//	ft_putnbr(env->tab.cy);
//	ft_putchar('\n');
	env->coef = 5;
//	env->coef = 10 % (env->tab.j * env->tab.i);
//	ft_putnbr(env->coef);
//	ft_putchar('\n');
}

int		expose_hook(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	iso(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}

void	display_win(t_env *env)
{
	mlx_key_hook(env->win, key_funct, env);
	mlx_expose_hook(env->win, expose_hook, env);
	ft_putstr("disp\n");
}
