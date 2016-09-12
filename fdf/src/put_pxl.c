/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:41:23 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/12 18:06:52 by ahoareau         ###   ########.fr       */
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
	env->coef = 10;
	y = 0;
	env->tab.i = env->tab.i * env->coef;
	env->tab.j = env->tab.j * env->coef;
	while (y < (env->tab.i))
	{
		x = 0;
		j = 0;
		while (x < (env->tab.j))
		{
//			ft_putnbr(i);
//			ft_putchar(' ');
//			ft_putnbr(j);
//			ft_putchar(' ');
//			ft_putnbr(env->tab.j);
//			ft_putchar(' ');
//			ft_putnbr(env->tab.tab[i][j]);
//			ft_putchar('\n');
			if (env->tab.tab[i][j] > 0)
			{
				mlx_pixel_put(env->mlx, env->win, x, y, 0xA800AF);
			}
			else
				mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
			x += env->coef;
			j++;
		}
//		ft_putstr("##########");
		y += env->coef;
		i++;
//		ft_putnbr(y);
//		ft_putchar('\n');
	}
}


//segfault ds les deplacements avec les fleche, comprendre comment sauvegarder une data ds la structure
