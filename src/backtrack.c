/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:33:31 by ggane             #+#    #+#             */
/*   Updated: 2016/03/08 15:39:52 by ggane            ###   ########.fr       */
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
		if (j == 3)
			break ;
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
			if (tmp->p[i] >= 4 && res > 4)
				tmp->p[i] = tmp->p[i] + (res - 4);
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
		if (j == 3)
			break ;
		tmp = tmp->next;
		i++;
	}
}

int		backtracking(t_node *tmp, t_tetri *forme, int *tab, int i, char letter)
{
	if (tmp == NULL)
		return (0);
	if (tmp->data != '.' && tmp->next != NULL)
	{
		return (backtracking(tmp->next, forme, tab, i, letter));
	}
	if (tmp->pos == tab[i])
	{
		design_letters(tmp, forme->prev, '.');
	}
	if (tmp->data == '.')
	{
		if (non_present(tmp, forme))
		{
			tab[i++] = tmp->pos;	
			design_letters(tmp, forme, letter++);
			if (tmp->next != NULL && forme->next != NULL)
			{
				return (backtracking(tmp->next, forme->next, tab, i, letter));
			}
		}
		else
		{
			return (backtracking(tmp->prev, forme, tab, i - 1, letter));
		}
	}
	tmp->data = 'X';
	//design_letters(tmp, forme, letter);
	return (1);
}

int		*stocke_nbT(int nbT)
{
	int	*tab;

	tab = (int*)malloc(sizeof(int) * nbT);
	if (tab)
		return (tab);
	return (NULL);
}
