/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:58:29 by ggane             #+#    #+#             */
/*   Updated: 2016/03/23 10:56:28 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_system_call(char *file)
{
	int		fd;
	int		i;
	char	buf[BUF_SIZE];
	char	*str;

	printf("c_s_c start\n");
	i = 0;
	if ((fd = open(file, O_RDONLY)))
		while (read(fd, buf, BUF_SIZE))
			i++;
	close(fd);
	str = (char*)malloc(sizeof(char) * i);
	if (!str)
		return (1);
	fd = open(file, O_RDONLY);
	read(fd, str, i);
	close(fd);
	if (check_file(str))
	{
		printf("check_file(str) return :ERROR\n");
		return (1);
	}
	free(str);
	printf("c_s_c end OK\n");
	return (0);
}

int		check_file(char *file)
{
	int		i;
	int		j;
	char	*schema;

	i = 0;
	j = 0;
	if (!(schema = (char *)malloc(sizeof(char) * 21)))
		return (1);
	while (file[i])
	{
		if (j != 19)
			schema[j] = file[i];
		if (j == 19)
		{
			//printf("i = %d\n", i);
			//printf("\n-----\n%s\n-----\n", schema);
			if (check_forme(schema))
			{
				printf("check_forme(schema) return ERROR\n");
				return (1);
			}
			if (file[i + 1] != '\n' && file[i + 1] != '\0')
			{
				printf("file[i] : [%c]\n", file[i]);
				printf("file[i + 1] = [%c] est different de n ou de 0\n", file[i + 1]);
				return (1);
			}
			if (file[i + 1] != '\0')
				i = i + 1;
			j = -1;
		}
		i++;
		j++;
	}
	free(schema);
	return (0);
}

int		check_forme(char *schema)
{
	int		i;
	int		j;
	int		l;
	int		sharp;
	int		*doublon;

	i = 0;
	j = 0;
	l = 0;
	sharp = 0;
	doublon = malloc(sizeof(int) * SIZE);
	printf("check_forme start\n");
	if (!doublon)
		return (1);
	while (i < SIZE)
		doublon[i++] = -1;
	i = 0;
	//affiche_tab(doublon);
	while (schema[i])
	{
		if (schema[i] == '#')
		{
			sharp++;
			if (sharp == 1)
				printf("i dans check_forme : %d\n", i);
			doublon[l++] = i;
			if (schema[i - 1] == '#' && i - 1 >= 0)
				doublon[l++] = i - 1;
			if (schema[i + 1] == '#' && schema[i + 1] != '\0')
				doublon[l++] = i + 1;
			if (schema[i - 5] == '#' && i - 5 >= 0)
				doublon[l++] = i - 5;
			if (schema[i + 5] == '#' && schema[i + 5] != '\0')
				doublon[l++] = i + 5;
			//printf("diese nb : %d\n", sharp);
			//affiche_tab(doublon);
		}
		i++;
	}
	if (check_doublons(doublon) == 1)
	{
		free(doublon);
		printf("check_forme end : error - pas de doublons\n");
		return (1);
	}
	free(doublon);
	if (sharp != 4)
	{
		printf("check_forme end : error - sharp != 4\n");
		return (1);
	}
	//printf("check_forme end : succes\n");
	return (0);
}

void	affiche_tab(int *doublon)
{
	int		j = 0;

	printf("doublon :\n");
	while (j < (SIZE / 2))
	{

		if (doublon[j + (SIZE / 2)] == -1 || doublon[j + (SIZE / 2)] > 9)
		printf("[%d] = %d | [%d] = %d\n", j, doublon[j], j + (SIZE / 2), doublon[j + (SIZE / 2)]);
		j++;
	}
}

int		check_doublons(int *tab)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	printf("check_doublons : start\n");
	affiche_tab(tab);
	while (k < 16)
	{
		while (i < 16)
		{
			if (tab[k] == tab[i])
			{
				j++;
				//printf("doublon tab[%d] : %d\n", i, tab[i]);
			}
			i++;
		}
		if (j < 2 && tab[k] != -1)
			return (1);
		j = 0;
		i = 0;
		k++;
	}
	printf("check_doublons : end\n");
	return (0);
}
