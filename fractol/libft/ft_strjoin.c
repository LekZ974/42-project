/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:26:15 by ahoareau          #+#    #+#             */
/*   Updated: 2016/05/01 19:18:19 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_join(char *dst, char const *s2, unsigned int i, char *tmp)
{
	size_t			len;
	unsigned int	j;

	len = ft_strlen(tmp);
	j = 0;
	while (j < len)
	{
		dst[i] = tmp[j];
		i++;
		j++;
	}
	if (tmp == s2)
		return (dst);
	return (fill_join(dst, s2, i, (char *)s2));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t			size;
	char			*join;
	unsigned int	i;

	if (s1 != NULL && s2 != NULL)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		join = ft_memalloc(size + 1);
		i = 0;
		if (join != NULL)
		{
			fill_join(join, s2, i, (char *)s1);
			return (join);
		}
	}
	return (NULL);
}
