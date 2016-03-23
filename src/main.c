/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:51:28 by ggane             #+#    #+#             */
/*   Updated: 2016/03/23 12:45:20 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (check_system_call(av[1]))
			ft_putstr("error\n");
		else
			open_close(av[1]);
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
