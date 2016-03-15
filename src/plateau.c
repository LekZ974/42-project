/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:27:50 by ahoareau          #+#    #+#             */
/*   Updated: 2016/03/15 18:24:42 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		open_close(char *file)
{
	int		fd;
	int		index;
	int		i;
	int		j;
	int		k;
	int		nbT;
	int		res;
	t_list	*list1;
	t_tlist	*list2;
	t_node	*tmp;
	t_tetri *forme;
	char	buf[BUF_SIZE];

	index = 0;
	i = 0;
	j = 0;
	k = 0;
	list1 = create_list(); //donne acces a liste plateau
	list2 = create_ttlist(); //donne acces a liste tetriminos
	fd = open(file, O_RDONLY);	//lecture fichier
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			index++;
	}
	close(fd);
	nbT = (index / 5) + 1;
	res = ft_sqrt(nbT * 4);		// res = cote carre
	list1 = dessine_carre(list1, res);
	add_tetriminos(file, list2);
	printf("coordonnees tetriminos sur carre 4 x 4\n\n");
	//affiche_coord(list2);
	square_converter(list2, 4, res);
	tmp = list1->head;
	forme = list2->head;
	backtracking(list1, list2, tmp, forme);
	printf("coordonnees tetriminos sur carre %d x %d\n\n", res, res);
	//affiche_coord(list2);
	display_square(list1);
	list_delete(&list1);	// suppression liste
	ttlist_delete(&list2);	// suppression liste
	return (0);
}

t_list	*dessine_carre(t_list *list, int res)
{
	int		i;
	int		l;

	i = 0;
	l = 1;
	while (i < (res * res))		// creation plateau avec liste doublechaine
	{
		list = push_back(list, i, '.', res);
		if (l == res)
		{
			list = push_back(list, i, '\n', res);
			l = 0;
		}
		l++;
		i++;
	}
	return (list);
}

int		ft_sqrt(int nb)
{
	int		count;

	count = 0;
	while (count * count < nb)
		count++;
	if (count * count == nb)
		return (count);
	else
		return (ft_sqrt(nb + 1));
	return (0);
}
