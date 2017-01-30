/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:22:56 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/26 13:23:42 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strpos(const char *str, char c)
{
	const char	*start;

	start = str;
	while (*str)
	{
		if (*str == c)
			return (str - start);
		str++;
	}
	return (str - start);
}
