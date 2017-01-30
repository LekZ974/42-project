/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:35:44 by ahoareau          #+#    #+#             */
/*   Updated: 2016/12/18 20:45:40 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_frac		*init_frac(void)
{
	t_frac	*frac;

	frac = (t_frac *)malloc(sizeof(t_frac) * 5);
	frac->itmax = 50;
	frac->it = 0;
	frac->x1 = -2.1;
	frac->x2 = 0.6;
	frac->y1 = -1.2;
	frac->y2 = 1.2;
	frac->zoom = 100;
	frac->tmp = 0;
	frac->z.r = 0;
	frac->z.i = 0;
	frac->c.r = 0;
	frac->c.i = 0;
	ft_putendl("init frac");
	return (frac);
}
