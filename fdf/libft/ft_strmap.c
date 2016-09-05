/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:26:50 by ahoareau          #+#    #+#             */
/*   Updated: 2016/05/01 19:09:07 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*map;
	unsigned int	i;

	i = 0;
	map = ft_strdup(s);
	if ((s != NULL || f != NULL) && map != NULL)
	{
		while (map[i])
		{
			map[i] = f(map[i]);
			i++;
		}
		return (map);
	}
	return (NULL);
}
