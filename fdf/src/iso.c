/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 15:07:24 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/21 15:54:44 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_coord		get_point(t_env *env, int x, int y, int z)
{
	t_coord		p;
	int			i;
	int			j;

	i = y;
	j = x;
	x *= env->coef;
	y *= env->coef;
	p.x = (x) + env->tab.cx;
	ft_putnbr(env->tab.tab[i][j]);
	ft_putchar('-');
	ft_putnbr(env->tab.cy);
	ft_putchar('-');
	ft_putnbr(j);
	ft_putchar('-');
	ft_putnbr(i);
	ft_putchar('\n');
	p.y = (y / 2) - env->tab.tab[i][j] + env->tab.cy;
	p.z = z;
	ft_putstr("iso2\n");
	return (p);
}

void	iso(t_env *env)
{
	int			x;
	int			y;
	t_coord		p1;
	t_coord		p2;

	x = 0;
	while (x < env->tab.j)
	{
		y = env->tab.i;
		while (y >= 0)
		{
			ft_putstr("iso1\n");
			p1 = get_point(env, x, y, env->tab.tab[y][x]);
			env->p1 = p1;
			if (x < env->tab.j)
			{
				ft_putstr("iso\n");
				p2 = get_point(env, x, y, env->tab.tab[y + 1][x]); // segf ici!!
				env->p2 = p2;
				draw_lign(env);
			}
			if (y < env->tab.i)
			{
				p2 = get_point(env, x, y, env->tab.tab[y][x + 1]);
				env->p2 = p2;
				draw_lign(env);
			}
			y--;
		}
		x++;
	}
}
