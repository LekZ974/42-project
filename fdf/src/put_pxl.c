/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:41:23 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/05 18:28:09 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	pixel_put(t_env *env)
{
	int		n;
	int		i;
	int		x;
	int		y;

	n = 0;
	i = 0;
	env->coef = 10;
	env->tab.y = 250;
	y = env->tab.y;
	while (env->tab.y <= (y + (env->tab.i * env->coef)))
	{
		printf("env->tab.y = %d\n env->tab.x = %d\n env->tab.i = %d\n env->tab.j = %d\n##############\n",env->tab.y, env->tab.x, env->tab.i, env->tab.j);
		//ft_putendl("allumer pixl1\n");
		env->tab.x = 250;
		x = env->tab.x;
		while (env->tab.x <= (x + (env->tab.j * env->coef)))
		{
//			printf("##%d##\n", env->tab.tab[i][n]);
			if (env->tab.tab[i][n++] == 10)
				mlx_pixel_put(env->mlx, env->win, env->tab.x, env->tab.y, 0xA800AF);
			else
			//ft_putendl("allumer pixl\n");
				mlx_pixel_put(env->mlx, env->win, env->tab.x, env->tab.y, 0xFFFFFF);
			env->tab.x += env->coef;
			printf("           env->tab.y = %d\n env->tab.x = %d\n env->coef = %d\n env->tab.i = %d\n env->tab.j = %d\n##############\n",env->tab.y, env->tab.x, env->coef, env->tab.i, env->tab.j);
		}
		env->tab.y += env->coef;
	}
}


//comprendre pkoi le tableau se rempli bien quune fois sur quatre...
//segfault ds les deplacements avec les fleche, comprendre comment sauvegarder une data ds la structure
