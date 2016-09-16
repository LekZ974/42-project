/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 13:41:19 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/16 16:44:55 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	disp_window(t_env *env)
{
	env->xwin = 2024;
	env->ywin = 960;
	env->tab.cy = 300 % (env->tab.i * env->ywin);
	env->tab.cx = 400 % (env->tab.j * env->xwin);
//	ft_putnbr(env->tab.cx);
//	ft_putchar('\n');
//	ft_putnbr(env->tab.cy);
//	ft_putchar('\n');
	env->coef = 5;
//	env->coef = 10 % (env->tab.j * env->tab.i);
//	ft_putnbr(env->coef);
//	ft_putchar('\n');
}
