/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:24:31 by ahoareau          #+#    #+#             */
/*   Updated: 2016/02/26 11:01:47 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*create_list(void)								// creation liste
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (list)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	return (list);
}

t_tlist	*create_ttlist(void)								// creation liste
{
	t_tlist	*list;

	list = malloc(sizeof(*list));
	if (list)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	return (list);
}

t_list	*push_back(t_list *list, int position)		// ajout fin de liste
{
	t_node	*new;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->data = '.';
		new->pos = position;
		new->next = NULL;
		if (list->tail == NULL)
		{
			new->prev = NULL;
			list->head = new;
			list->tail = new;
		}
		else
		{
			list->tail->next = new;
			new->prev = list->tail;
			list->tail = new;
		}
		if (list->head == NULL)
			list->head = new;
	}
	return (list);
}

void	list_delete(t_list **list)				// suppression liste
{
	t_node	*tmp;
	t_node	*del;

	tmp = (*list)->head;
	while (tmp)
	{
		del = tmp;
		free(del);
		tmp = tmp->next;
	}
	free(*list);
	*list = NULL;
}

void	ttlist_delete(t_tlist **list)				// suppression liste
{
	t_tetri	*tmp;
	t_tetri	*del;

	tmp = (*list)->head;
	while (tmp)
	{
		del = tmp;
		free(del);
		tmp = tmp->next;
	}
	free(*list);
	*list = NULL;
}

t_tetri		*create_link(int *data)
{
	t_tetri	*new;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->p[0] = data[0];
		new->p[1] = data[1];
		new->p[2] = data[2];
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

t_tlist		*append_tetri(t_tlist *list, int *data)		// ajout fin de liste
{
	t_tetri		*new;

	new = create_link(data);
	new->next = NULL;
	if (list->tail == NULL)
	{
		new->prev = NULL;
		list->head = new;
		list->tail = new;
	}
	else
	{
		list->tail->next = new;
		new->prev = list->tail;
		list->tail = new;
	}
	if (list->head == NULL)
		list->head = new;
	return (list);
}
