/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:27:03 by ahoareau          #+#    #+#             */
/*   Updated: 2016/02/22 19:54:16 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_square(t_list *list, int res)
{
	t_node	*tmp;
	int		i;
	int		j;

	tmp = list->head;
	i = 1;
	j = 0;
	while (tmp)
	{
		ft_putchar(tmp->data);
		if (i == res)
		{
			ft_putchar('\n');
			i = 0;
		}
		i++;
		tmp = tmp->next;
		j++;
	}
	printf("j = %d\n", j);
}
