/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:24:31 by ahoareau          #+#    #+#             */
/*   Updated: 2016/02/23 17:01:07 by ahoareau         ###   ########.fr       */
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
