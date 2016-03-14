/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:27:50 by ahoareau          #+#    #+#             */
/*   Updated: 2016/03/14 18:58:49 by ggane            ###   ########.fr       */
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
	int		l;
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
	//nbT = 20;
	res = ft_sqrt(nbT * 4);		// res = cote carre
	l = 1;
	while (i < (res * res))		// creation plateau avec liste doublechaine
	{
		list1 = push_back(list1, i, '.');
		if (l == res)
		{
			list1 = push_back(list1, i, '\n');
			l = 0;
		}
		l++;
		i++;
	}
	add_tetriminos(file, list2);
	printf("coordonnees tetriminos sur carre 4 x 4\n\n");
	affiche_coord(list2);
	square_converter(list2, res);
	tmp = list1->head;
	forme = list2->head;
	backtracking(list1, list2, tmp, forme);
	printf("coordonnees tetriminos sur carre %d x %d\n\n", res, res);
	affiche_coord(list2);
	display_square(list1);
	list_delete(&list1);	// suppression liste
	ttlist_delete(&list2);	// suppression liste
	return (0);
}

t_list	*dessine_carre(in)
{
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
