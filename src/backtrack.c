/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:33:31 by ggane             #+#    #+#             */
/*   Updated: 2016/03/06 09:44:51 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		non_present(t_node *elem, t_tetri *forme)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (elem)
	{
		if (forme->p[j] == i)
		{
			if (elem->data != '.')
				return (0);
			i = 0;
			j++;
		}
		if (j == 2)
			j = 0;
		j = 0;
		elem = elem->next;
		i++;
	}
	return (1);
}

void	square_converter(t_tlist *list, int res)
{
	t_tetri		*tmp;
	int			i;

	tmp = list->head;
	i = 0;
	while (tmp)
	{
		while (i < 3)
		{
			if (tmp->p[i] >= 4)
				tmp->p[i] += res;
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
}

void	design_letters(t_node *tmp, t_tetri *forme, char letter)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp->data = letter;
	while (tmp)
	{
		if (forme->p[j] == i)
		{
			tmp->data = letter;
			i = 0;
			j++;
		}
		if (j == 2)
			j = 0;
		tmp = tmp->next;
		i++;
	}
}

int		backtracking(t_list *list1, t_tlist *list2, char letter)
{
	t_node	*tmp;
	t_tetri	*forme;

	tmp = list1->head;
	forme = list2->head;
	/*while (tmp)
	{
		tmp2 = tmp;
		tmp3 = tmp;
		if (tmp->data == '.' && non_present(tmp2, forme) != 0)
		{
			design_letters(tmp3, forme, letter);
			letter++;
			if (forme->next)
				forme = forme->next;
		}
		tmp = tmp->next;
	}*/

	design_letters(tmp, forme, letter);
	return (1);
}
