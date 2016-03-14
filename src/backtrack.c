/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:33:31 by ggane             #+#    #+#             */
/*   Updated: 2016/03/14 18:35:41 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_placeable(t_node *tmp, t_tetri *forme, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (tmp->data != c)
		return (0);
	while (tmp)
	{
		if (forme->coordonnees[j] == i)
		{
			if (tmp->data != c)
				return (0);
			if (tmp == NULL)
				return (0);
			i = 0;
			j++;
		}
		if (j == 3)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL && j < 3)
		return (0);
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
			if (tmp->coordonnees[i] >= 4 && res > 4)
				tmp->coordonnees[i] = tmp->coordonnees[i] + (res - 4);
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
	forme->position = tmp->position;
	while (tmp)
	{
		if (forme->coordonnees[j] == i)
		{
			tmp->data = letter;
			i = 0;
			j++;
		}
		if (j == 3)
			break ;
		tmp = tmp->next;
		i++;
	}
}

int		backtracking(t_list *list, t_tlist *flist, t_node *tmp, t_tetri *forme)
{
	if (forme == NULL)
	{
		printf("job done\n");
		return (0);
	}
	while (is_placeable(tmp, forme, '.')) // place forme a emplacement precis
	{
		design_letters(tmp, forme, forme->letter);
		return (backtracking(list, flist, tmp->next, forme->next));
	}
	if (is_placeable(tmp, forme, '.') == 0 && tmp->next != NULL) // essaie de placer forme actuelle a position + 1
	{
		printf("\n1er if\ntmp->position : %d\nforme->nb : %d\nletter : %c\n", tmp->position, forme->nb, forme->letter);
		return (backtracking(list, flist, tmp->next, forme));
	}
	if (is_placeable(tmp, forme, '.') == 0 && tmp->next == NULL) // essaie de place forme prec a position ancienne + 1
	{
		tmp = tetriminos_prev(list, tmp, forme->prev);
		printf("\n2nd if\ntmp->position : %d\nforme->nb : %d\nletter - 1 : %c\n", tmp->position, forme->prev->nb, forme->prev->letter);
		if (is_placeable(tmp, forme->prev, forme->prev->letter)) //check si forme prec peut etre effacee
		{
			printf("if debut\n");
			design_letters(tmp, forme->prev, '.');
			printf("if fin\n");
		}
		if (tmp->next != NULL && forme->prev != flist->head)
			return (backtracking(list, flist, tmp->next, forme->prev));
	}
	//tmp->data = 'X';
	return (0);
}

t_node	*tetriminos_prev(t_list *list, t_node *tmp, t_tetri *forme)
{
	int		i = 1;

	while (forme->position != tmp->position && tmp->prev != list->head)
	{
		tmp = tmp->prev;
		i++;
	}
	printf("tours tetriminos_prev : %d\n", i);
	//tmp->data = 'Z';
	return (tmp);
}
