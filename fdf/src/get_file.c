/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:57:58 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/12 14:40:17 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int		count(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			j++;	
			while (line[i] != ' ')
			{
				i++;
				if (line[i] == '\n' || line[i] == '\0')
					return (j);
			}
		}
		i++;
	}
	return(j);
}

//converti les colonnes en int
void	get_int(int i, t_env *env, char *line)
{
	int		n;
	int		j;

	n = 0;
	j = 0;
	while (line[n] != '\0')
	{
		if (line[n] != ' ' && line[n] != '\0')
		{
			env->tab.tab[i][j] = line[n] - '0';
			n++;
			while (line[n] != ' ' && line[n] != '\0')
			{
				env->tab.tab[i][j] = env->tab.tab[i][j] * 10 + line[n] - '0';
				n++;
			}
			j++;
		}
		if (line[n] == ' ')
			n++;
	}
}

//malloc la map
void	mall_tab(int fd, t_env *env)
{
	int		n;
	char	*line;
	int		**tab;

	n = 0;
	tab = NULL;
	env->tab.i = 0; 
	while (get_next_line(fd, &line))
	{
		if (env->tab.i == 0)
			env->tab.j = count(line);
		env->tab.i++;
	}
	tab = (int **)malloc(sizeof(int *) * env->tab.i);		//malloc la taille de la map (nb ligne)
	if (tab == NULL)
	{
		ft_putendl("Probleme allocation memoire -> map.\n");
		exit(1);
	}
	while (n <= env->tab.i)
	{
		tab[n] = (int *)malloc(sizeof(int) * env->tab.j);
		if (tab[n] == NULL)
			exit(1);
		n++;
	}
	env->tab.tab = tab;
}

t_env		*get_tab(char *str, t_env *env)
{
	int		fd;
	int		fd2;
	int		i;
	char	*line;

	i = 0;
	fd = open(str, O_RDONLY);
	fd2 = open(str, O_RDONLY);
	mall_tab(fd, env);
	close(fd);
	while (get_next_line(fd2, &line))
	{
		get_int(i, env, line);
		i++;
	}
	close(fd2);
	return (env);
}
