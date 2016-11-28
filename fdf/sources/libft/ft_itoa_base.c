/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:42:22 by ahoareau          #+#    #+#             */
/*   Updated: 2016/05/23 17:13:28 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*complete_str(int value, int base, char *s, int len)
{
	static char		*str_base;
	int				start;

	str_base = "0123456789ABCDEF";
	start = 0;
	if (base == 10 && value < 0)
	{
		s[0] = '-';
		value *= -1;
		start = 1;
	}
	if (value < 0)
		value *= -1;
	s[len] = '\0';
	while (len-- > start)
	{
		s[len] = str_base[value % base];
		value = value / base;
	}
	return (s);
}

static int	len_str(int value, int base)
{
	int				size;

	size = 0;
	if (base == 10 && value < 0)
		size++;
	if (value < 0)
		value *= -1;
	while (value >= base)
	{
		value = value / base;
		size++;
	}
	return (size + 1);
}

static int	check_base(int base)
{
	if (base >= 2 && base <= 16)
		return (1);
	return (0);
}

char		*ft_itoa_base(int value, int base)
{
	unsigned int	len;
	char			*s;

	len = len_str(value, base);
	if (check_base(base))
	{
		s = (char *)malloc(sizeof(char) * len);
		if (s != NULL)
		{
			complete_str(value, base, s, len);
			return (s);
		}
	}
	return (NULL);
}
