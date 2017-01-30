/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:52:13 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/28 18:02:21 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		handling(t_env *e, t_tab *tab)
{
	t_data	data;

	data.e = e;
	data.tab = tab;
	mlx_hook(e->win, 2, (1L < 10), key_funct, &data);
	mlx_hook(e->win, 17, (1L << 17), ft_quit, e);
	mlx_loop(e->mlx);
}

int			key_funct(int keycode, t_data *data)
{
	mlx_clear_window(data->e->mlx, data->e->win);
	if (keycode == 53)
		ft_quit(data->e);
	else if (keycode == 126 || keycode == 13)
		data->tab->pos.y += 10;
	else if (keycode == 125 || keycode == 1)
		data->tab->pos.y -= 10;
	else if (keycode == 123 || keycode == 0)
		data->tab->pos.x += 10;
	else if (keycode == 124 || keycode == 2)
		data->tab->pos.x -= 10;
	else if (keycode == 69 || keycode == 12)
	{
		data->tab->coef++;
		if (data->tab->amp != 0)
			data->tab->amp++;
	}
	else if (data->tab->coef != 1 && (keycode == 78 || keycode == 14))
	{
		data->tab->coef--;
		if (data->tab->amp != 0)
			data->tab->amp--;
	}
	key_funct_2(keycode, data);
	return (0);
}

int			key_funct_2(int keycode, t_data *data)
{
	if (keycode == 75 || keycode == 15)
		data->tab->amp--;
	else if (keycode == 67 || keycode == 17)
		data->tab->amp++;
	else if (keycode == 84)
		data->tab->rotx *= -1;
	else if (keycode == 83)
		data->tab->roty *= -1;
	else if (keycode == 71 || keycode == 50)
		data_handing(data->tab);
	if (keycode == 76)
		display_param(data->e);
	parse(data->tab);
	draw(data->e, data->tab);
	return (0);
}

int			ft_quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}
