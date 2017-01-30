/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:18:17 by ahoareau          #+#    #+#             */
/*   Updated: 2016/04/29 10:18:18 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone_memoire;

	zone_memoire = malloc(size);
	if (zone_memoire)
	{
		ft_bzero(zone_memoire, size);
		return (zone_memoire);
	}
	else
		return (NULL);
}
