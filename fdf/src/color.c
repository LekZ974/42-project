/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:44:21 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/28 17:42:09 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		get_level(int z1, int z2, t_tab *tab)
{
	int		level;
	int		z;

	level = 0;
	z = (z1 + z2) / 2;
	if (z == tab->zmin)
		return (1);
	if (z > tab->zmin && z < tab->zmid / 2)
		return (2);
	if (z >= tab->zmid / 2 && z < tab->zmid)
		return (3);
	if (z >= tab->zmid && z < tab->zmax)
		return (4);
	if (z == tab->zmax)
		return (5);
	return (0);
}

int		ft_color(t_tab *tab)
{
	int		z1;
	int		z2;
	int		color;

	z1 = tab->z1;
	z2 = tab->z2;
	color = 0xFFFFFF;
	if (z1 < tab->zmin || z1 > tab->zmax)
		return (0);
	if (z2 < tab->zmin || z2 > tab->zmax)
		return (0);
	else if (get_level(z1, z2, tab) == 1)
		color = 0x0066FF;
	else if (get_level(z1, z2, tab) == 2)
		color = 0x33FF00;
	else if (get_level(z1, z2, tab) == 3)
		color = 0xFFCC00;
	else if (get_level(z1, z2, tab) == 4)
		color = 0xFF3300;
	else if (get_level(z1, z2, tab) == 5)
		color = 0x660000;
	else
		color = 0xFFFFFF;
	return (color);
}
