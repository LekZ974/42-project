/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:33:31 by ggane             #+#    #+#             */
/*   Updated: 2016/03/23 12:43:24 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		est_dessinable(t_node *tmp, t_tetri *forme, char c)
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
			if (tmp->coordonnees[i] > 1 && cote2 != cote1)
				tmp->coordonnees[i] = tmp->coordonnees[i] + (cote2 - cote1);
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
}

void	dessine_forme(t_node *tmp, t_tetri *forme, char letter)
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
	if (forme == NULL) //toutes les formes ont ete placee. Resolution terminee.
	{
		printf("job done\n\n");
		display_square(list);
		list_delete(&list);
		return (0);
	}
	while (est_dessinable(tmp, forme, '.') != 0)// check si forme peut etre placee a emplacement tmp
	{
		//printf("\nplacement : %c en position : %d = SUCCESS !!!\n\n", forme->letter, tmp->position);
		dessine_forme(tmp, forme, forme->letter); // si Est_Dessinable OK, alors la forme est placee
		return (backtracking(list, flist, list->head, forme->next)); //Deplacement d'un cran pour tester forme suivante
	}
	if (est_dessinable(tmp, forme, '.') == 0 && tmp->next != NULL) // forme non placee, mais il reste emplacements a tester
	{
		//printf("tentative placement : %c en position : %d = failed\n", forme->letter, tmp->position);
		return (backtracking(list, flist, tmp->next, forme));
	}
	if (est_dessinable(tmp, forme, '.') == 0 && tmp->next == NULL && forme->letter == 'A') // carre trop petit
	{
		//printf("\nAUGMENTATION CARRE DE TAILLE %d A TAILLE %d : SUCCESS !!!\n", tmp->cote, tmp->cote + 1);
		list = carre_sup(list, flist);
		return (backtracking(list, flist, list->head, forme));
	}
	if (est_dessinable(tmp, forme, '.') == 0 && tmp->next == NULL) // forme non placee, tous les emplacements testes
	{
		//printf("\ntentative placement : %c = TOTAL FAIL !!!\n\n", forme->letter);
		table_rase(list, forme->prev); //la forme precedente et toutes les suivantes sont effacee du carre
		tmp = forme_prev(list, tmp, forme->prev); //tmp = emplacement forme precedente (deja effacee)
		if (tmp->next != NULL && forme->prev != flist->head->prev)
		{
			//printf("deplacement : %c en position : %d\n", forme->prev->letter, tmp->next->position);
			return (backtracking(list, flist, tmp->next, forme->prev)); //positionne forme precedente sur emplacement suivant
		}
	}
	return (1);
}

t_node	*forme_prev(t_list *list, t_node *tmp, t_tetri *forme)
{
	while (forme->position != tmp->position && tmp->prev != list->head->prev)
		tmp = tmp->prev;
	return (tmp);
}

t_list	*carre_sup(t_list *list, t_tlist *flist)
{
	int		cote;
	t_node	*tmp;

	tmp = list->head;
	cote = tmp->cote;
	list_delete(&list);
	list = create_list();
	list = dessine_carre(list, cote + 1);
	//display_square(list);
	square_converter(flist, cote, cote + 1);
	return (list);
}

void	table_rase(t_list *list, t_tetri *patron)
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
	if (patron->nb == 1 && patron->next != NULL)
	{
		//printf("effacement : %c = OK\n", patron->letter);
		patron = patron->next;
	}
	while (patron->position != 0 && patron->nb != 1 && patron->next != NULL)
	{
		//printf("effacement : %c = OK\n", patron->letter);
		patron = patron->next;
	}
	//printf("\n");
}
