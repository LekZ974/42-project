/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:57:58 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/05 17:36:56 by ahoareau         ###   ########.fr       */
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
	//	printf("%c %d\n", line[i], j);
		if (line[i] != ' ' && line[i] != '\n')
			j++;
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
	while (line[j] != '\0')
	{
//		printf("line[j] = %c ## i = %d ## n = %d ## env->tab.tab = %d\n", line[j], i, n, env->tab.tab[i][n]);
		if (line[j] != ' ' && line[j] != '\0')
		{
			env->tab.tab[i][n] = line[j] - '0';
			j++;
			while (line[j] != ' ' && line[j] != '\0')
			{
				env->tab.tab[i][n] = env->tab.tab[i][n] * 10 + line[j] - '0';
				j++;
			}
//		printf("####line[j] = %c ## i = %d ## n = %d ## env->tab.tab = %d####\n", line[j], i, n, env->tab.tab[i][n]);
			n++;
		}
		if (line[j] == ' ')
			j++;
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
//		printf("count(line) = %d\n", count(line));
		env->tab.i++;
	}
	tab = (int **)malloc(sizeof(int) * env->tab.i);		//malloc la taille de la map (nb ligne)
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

void		get_tab(char *str, t_env *env)
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
}
