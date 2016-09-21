/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 13:49:10 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/19 17:19:45 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check(char *file)
{
	char	*str;

	if (exist_file(file))				//regarde si fichier existe ret = 0 OK
		return (1);
	str = fill_str(file);
	if (check_file(str))			//regarde si ok ret = 0 OK
		return (1);
	free(str);
	return (0);
}

char	*fill_str(char *file)		//li le fichier et ret chaine character
{
	int		fd;
	int		i;
	char	buf[BUFF_SIZE];
	char	*str;

	i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buf, 1))
		i++;
	close(fd);
	fd = open(file, O_RDONLY);
	str = malloc(sizeof(char) * i);
	if (str == NULL)
		return (NULL);
	read(fd, str, i);
	close(fd);
	return (str);
}

int		fdf(char *str)
{
	t_env	*env;

	env = NULL;
	ft_putendl(str);
	env = malloc(sizeof(t_env));
	if (env == NULL)
	{
		ft_putendl("Probleme allocation memoire.\n");
		exit(1);
	}
	env->mlx = mlx_init();
	env = get_tab(str, env);
	disp_window(env);
	env->win = mlx_new_window(env->mlx, WIDTH, LENGTH, "fdf");
	env->img.img = mlx_new_image(env->mlx, WIDTH, LENGTH);
	env->img.data = mlx_get_data_addr(env->img.img, &env->img.bpp, &env->img.sl, &env->img.endian);
	display_win(env);
	write(1, "OK\n", 3);
	mlx_loop(env->mlx);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (check(av[1]) == 1)				//check le fichier ret 0 OK
			ft_putstr("error\n");
		else
			fdf(av[1]);			// analyse le fichier
	}
	else
		ft_putstr("usage: ./fdf source_file\n");
	return (0);
}
