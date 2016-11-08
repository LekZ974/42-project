/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 13:49:10 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/05 16:01:14 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf(char *str)
{
	t_env	*e;

	e = NULL;
	e = (t_env *)malloc(sizeof(t_env));
	if (e == NULL)
		exit(1);
	e->mlx = mlx_init();
	e->file = str;
	disp_window(e);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fdf");
	e = get_tab(e);
	draw(e);
	mlx_hook(e->win, 2, (1L < 10), key_funct, e);
	mlx_loop(e->mlx);
	return (0);
}

int		main(int ac, char **av)
{
	ft_putendl(av[1]);
	if (ac == 2)
	{
		if (check(av[1]) == 1)
			ft_putstr("error\n");
		else
			fdf(av[1]);
	}
	else
		ft_putstr("usage: ./fdf source_file\n");
	return (0);
}
