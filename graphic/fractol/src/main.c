/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:33:27 by ahoareau          #+#    #+#             */
/*   Updated: 2016/12/18 19:19:41 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		fractol(void)
{
	t_env	*e;
	t_frac	*frac;

	e = init_env();
	frac = init_frac();
	handling(e, frac);
}

int			main(int ac, char **av)
{
	if (ac == 1)
	{
		av[1] = NULL;
		fractol();
	}
	else
		ft_putendl("usage : ./fractol");
	return (0);
}
