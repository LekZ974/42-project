/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:25:24 by ahoareau          #+#    #+#             */
/*   Updated: 2016/05/01 19:06:24 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	if (s1 != NULL)
	{
		copy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
		if (copy == NULL)
			return (NULL);
		else
			copy = ft_strcpy(copy, s1);
		return (copy);
	}
	return (NULL);
}
