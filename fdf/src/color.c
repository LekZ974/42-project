/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:05:43 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/06 17:54:40 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_color(t_env *e)
{
	int		color;

	if (e->level < 0)
	{
		color = 0xFFCC00;
		if (e->level < -50)
			color = 0xFF3300;
	}
	if (e->level >= 0)
	{
		color = 0x33FF00;
		if (e->level > 50)
			color = 0x333300;
	}
	return (color);
}
