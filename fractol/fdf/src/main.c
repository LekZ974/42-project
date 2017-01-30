/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:38:53 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/28 17:53:14 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		fdf(char *file)
{
	t_env	*e;
	t_tab	*tab;

	tab = init_tab();
	get_tab(file, tab);
	e = init_env();
	parse(tab);
	draw(e, tab);
	handling(e, tab);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (check(av[1]) == 1)
			ft_putendl("file doesn't exist / invalid file (*.fdf)");
		else
			fdf(av[1]);
	}
	else
		ft_putendl("usage : ./fdf source_file.fdf");
	return (0);
}
