/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:33:31 by ggane             #+#    #+#             */
/*   Updated: 2016/03/15 23:16:53 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		Est_Dessinable(t_node *tmp, t_tetri *forme, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (tmp->data != c)
		if (tmp->data != '.')
			return (0);
	while (tmp)
	{
		if (forme->coordonnees[j] == i)
		{
			 if (tmp->data != c)
				if (tmp->data != '.')
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

void	square_converter(t_tlist *list, int cote1, int cote2)
{
	t_tetri		*tmp;
	int			i;

	tmp = list->head;
	i = 0;
	while (tmp)
	{
		while (i < 3)
		{
			if (tmp->coordonnees[i] > 1 && cote2 > cote1)
				tmp->coordonnees[i] = tmp->coordonnees[i] + (cote2 - cote1);
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
}

void	Dessine_Forme(t_node *tmp, t_tetri *forme, char letter)
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
		printf("job done\n\n");
		return (0);
	}
	while (Est_Dessinable(tmp, forme, '.') != 0)// || Est_Dessinable(tmp, forme, forme->letter) != 0) // place forme a emplacement precis
	{
		printf("\nplacement : %c en position : %d SUCCESS !!!\n\n", forme->letter, tmp->position);
		Dessine_Forme(tmp, forme, forme->letter);
		return (backtracking(list, flist, tmp->next, forme->next));
	}
	if (Est_Dessinable(tmp, forme, '.') == 0 && tmp->next != NULL) // essaie de placer forme actuelle a position + 1
	{
		printf("tentative placement : %c en position : %d failed\n", forme->letter, tmp->position);
		return (backtracking(list, flist, tmp->next, forme));
	}
	if (Est_Dessinable(tmp, forme, '.') == 0 && tmp->next == NULL) // essaie de place forme prec a position ancienne + 1
	{
		printf("\ntentative placement : %c : TOTAL FAIL !!!\n\n", forme->letter);
		Table_Rase(list, forme->prev);
		tmp = Forme_Prev(list, tmp, forme->prev);
		if (tmp->next != NULL && forme->prev != flist->head->prev)
		{
			printf("deplacement : %c en position : %d\n", forme->prev->letter, tmp->next->position);
			return (backtracking(list, flist, tmp->next, forme->prev));
		}
	}
	return (0);
}

t_node	*Forme_Prev(t_list *list, t_node *tmp, t_tetri *forme)
{
	while (forme->position != tmp->position && tmp->prev != list->head->prev)
		tmp = tmp->prev;
	return (tmp);
}

t_list	*Carre_Sup(t_list *list)
{
	int		cote;
	t_node	*tmp;

	tmp = list->head;
	cote = tmp->cote;
	list_delete(&list);
	list = create_list();
	list = dessine_carre(list, cote + 1);
	return (list);
}

void	Table_Rase(t_list *list, t_tetri *patron)
{
	t_node	*tmp;
	t_tetri *forme;

	tmp = list->head;
	forme = patron;
	while (tmp)
	{
		while (forme)
		{
			if (tmp->data == forme->letter)
				tmp->data = '.';
			forme = forme->next;
		}
		forme = patron;
		tmp = tmp->next;
	}
	printf("\nTable_Rase :\n");
	display_square(list);
}
