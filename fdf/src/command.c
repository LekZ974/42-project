/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 13:02:47 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/17 16:19:17 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		key_funct(int keycode, t_env *env)
{
	env = env->win;
	printf("event key %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 126 || keycode == 13)
	{
//		printf("y = %d\n", env->tab.y);
//		env->tab.cy -= 10;
	}
	if (keycode == 125 || keycode == 1)
	{
//		env->tab.cy += 10;
	}
	if (keycode == 69)
	{
		env->coef += 5;
	}
	if (keycode == 78)
	{
		env->coef -= 5;
	}
	return (0);
}
