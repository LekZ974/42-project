/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:08:49 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/26 13:46:23 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long			ft_strtol_rec(char **str, int sign, int base)
{
	long	ret;
	int		i;

	ret = 0;
	while (**str && (i = ft_strpos(ALPHANUMS, ft_tolower(**str))) < base)
	{
		if (sign == -1)
			ret = ret * base - i;
		else
			ret = ret * base + i;
		(*str)++;															
	}
	return (ret);
}

long				ft_strtol(char *p, char **ret, int base)
{
	int		sign;
	long	res;

	sign = 1;
	while (*p == '-' || *p == '+')
	{
		if (*p == '-')
			sign = sign * -1;
		p++;
	}
	res = ft_strtol_rec(&p, sign, base);
	*ret = p;
	return (res);
}
