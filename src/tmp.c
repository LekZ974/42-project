/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 10:23:18 by ggane             #+#    #+#             */
/*   Updated: 2016/03/14 17:40:11 by ggane            ###   ########.fr       */
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
		printf("forme->nb : %d\n", tmp->nb);
		printf("forme->position : %d\n", tmp->position);
		printf("forme->letter : %c\n", tmp->letter);
		while (i < 3)
		{
			printf("forme->coordonnees[%d] : %d\n", i, tmp->coordonnees[i]);
			i++;
		}
		printf("\n");
		i = 0;
		tmp = tmp->next;
	}
}
