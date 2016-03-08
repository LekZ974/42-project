/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:27:03 by ahoareau          #+#    #+#             */
/*   Updated: 2016/03/08 11:24:39 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_square(t_list *list)
{
	t_node	*tmp;

	tmp = list->head;
	while (tmp)
	{
		ft_putchar(tmp->data);
		tmp = tmp->next;
	}
}
