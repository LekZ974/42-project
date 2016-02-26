/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:33:31 by ggane             #+#    #+#             */
/*   Updated: 2016/02/26 12:24:30 by ggane            ###   ########.fr       */
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
		while (j < 3)
		{
			if (forme->p[j] == i)
			{
				if (elem->data != '.')
					return (0);
				i = 0;
			}
			j++;
		}
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

int		backtracking(t_node *tmp,t_list *list1, t_tlist *list2, t_tetri *forme, char letter)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	letter = 'A';
	printf("start_backtrack\n");
	if (tmp == NULL)		//si liste parcourue entierement
		return (0);
	printf("if1 ok\n");
	if (tmp->data != '.' && tmp != NULL)	//si cellule pas vide
	{		
		printf("backtracking\n");
		return (backtracking(tmp->next, list1, list2, forme->next, letter++) == 0);
	}
	printf("if2 ok\n");
	if (non_present(tmp, forme) != 0)   //check obstacle
	{
		tmp->data = letter;
		while (tmp != NULL)
		{
			if (forme->p[j] == i)
			{
				tmp->data = letter;
				i = 0;
				j++;
				printf("BBBBBBBBB\n");
			}
			if (j == 2)
				j = 0;
			tmp = tmp->next;
			i++;
		printf("AAAAAAAA\n");
		}
		tmp = list1->head;
		if (backtracking(tmp->next, list1, list2, forme->next, letter++) == 0)	//si ok
		{
			return (0);
		}
	}
	printf("inwhile1 ok\n");
	printf("while1 ok\n");
	//tmp->data = '.';
	/*while (tmp->next != NULL)
	{
		if (forme->p[j] == i)
		{
			tmp->data = '.';
			i = 0;
			j++;
		}
		if (j == 2)
			j = 0;
		tmp = tmp->next;
		i++;
	}*/
	printf("end\n");
	return (1);
}
