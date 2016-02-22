/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:27:03 by ahoareau          #+#    #+#             */
/*   Updated: 2016/02/22 17:49:34 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_square(int res)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < res)
	{
		while (j < res)
		{
			ft_putchar('.');
			j++;
			if (j == res)
				ft_putchar('\n');
		}
		i++;
		j = 0;
	}
}
