/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:05:43 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/15 13:18:00 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_color(t_env *e)
{
	int		color;

	color = 0x33FF00;
	if (e->level > 50 && e->coord.y1 <= e->coord.y2)
	{
		color = 0x33FF33;
		if (e->level > 150 && e->coord.y1 <= e->coord.y2)
			color = 0x333300;
	}
	else if (e->level < -50)
	{
		if (e->level < 0 && e->coord.y1 == e->coord.y2)
			color = 0xFFCC00;
		if (e->level < -150 && e->coord.y1 == e->coord.y2)
			color = 0xFF3300;
	}
	return (color);
}
