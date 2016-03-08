/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 10:23:18 by ggane             #+#    #+#             */
/*   Updated: 2016/03/08 10:39:49 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	affiche_coord(t_tlist *list)
{
	t_tetri		*tmp;
	int			i;

	tmp = list->head;
	i = 0;
	while (tmp)
	{
		while (i < 3)
		{
			printf("forme->p[%d] : %d\n", i, tmp->p[i]);
			i++;
		}
		printf("\n");
		i = 0;
		tmp = tmp->next;
	}
}
