/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:49:29 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/28 17:45:15 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_env		*init_env(void)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fdf");
	return (e);
}

void		data_handing(t_tab *tab)
{
	tab->amp = 4;
	tab->coef = 5;
	tab->pos.x = 0;
	tab->pos.y = 0;
}

void		get_min_max(t_tab *tab)
{
	int		i;
	int		j;

	i = 0;
	tab->zmin = tab->input[0][0];
	tab->zmax = tab->zmin;
	while (i < tab->ymax)
	{
		j = 0;
		while (j < tab->xmax)
		{
			if (tab->input[i][j] > tab->zmax)
				tab->zmax = tab->input[i][j];
			if (tab->input[i][j] < tab->zmin)
				tab->zmin = tab->input[i][j];
			j++;
		}
		i++;
	}
	tab->zmid = (tab->zmin + tab->zmax) / 2;
}
