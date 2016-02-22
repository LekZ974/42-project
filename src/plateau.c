/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:27:50 by ahoareau          #+#    #+#             */
/*   Updated: 2016/02/22 19:40:50 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		open_close(char *file)
{
	int		fd;
	int		index;
	int		i;
	int		nbT;
	int		res;
	t_list	*list;
	char	buf[BUF_SIZE];

	index = 0;
	i = 0;
	list = create_list();
	fd = open(file, O_RDONLY);		//lecture fichier 
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			index++;
	}
	nbT = (index / 5) + 1;
	res = ft_sqrt(nbT * 4);			// res = cote carre
	while (i < (res * res))		// creation plateau avec liste doublechaine
	{
		list = push_back(list, i);
		i++;
	}
	display_square(list, res);
	printf("index : %d, nbT : %d\n, racine nbT : %d\n", index, nbT, ft_sqrt(nbT * 4));
	printf("i : %d\n", i);
	list_delete(&list);				// suppression liste
	close(fd);
	return (0);
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
