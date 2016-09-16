/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:41:23 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/16 16:36:30 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	pixel_put(t_env *env)
{
	int		j;
	int		i;
	int		x;
	int		y;

	j = 0;
	i = 0;
//	env->coef = 15;
	y = env->tab.cy;
	env->tab.i = env->tab.cy + env->tab.i * env->coef;
	env->tab.j = env->tab.cx + env->tab.j * env->coef;
	while (env->tab.cy < (env->tab.i))
	{
		x = env->tab.cx;
		j = 0;
		y = env->tab.cy;
		while (x < (env->tab.j))
		{
			if (env->tab.tab[i][j] > 0)
			{
//				ft_putchar('*');
//				ft_putnbr(y);
//				ft_putchar('\n');
//				ft_putnbr(env->tab.cy);
//				ft_putchar('\n');
				y -= env->tab.tab[i][j];	
				mlx_pixel_put(env->mlx, env->win, x, y, 0xA800AF);
				y += env->tab.tab[i][j];	
			}
			else
				mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
			x += env->coef;
			y -= env->coef / 2;
	//		ft_putnbr(y);
	//		ft_putchar('-');
			j++;
		}
//		ft_putstr("##########");
	//	ft_putnbr(i);
	//	ft_putchar('\n');
		i++;
		env->tab.cy += env->coef;
//		ft_putnbr(y);
//		ft_putchar('\n');
	}
}


//segfault ds les deplacements avec les fleche, comprendre comment sauvegarder une data ds la structure
