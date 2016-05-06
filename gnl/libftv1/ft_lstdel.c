/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:17:03 by ahoareau          #+#    #+#             */
/*   Updated: 2016/04/29 10:17:05 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*a_effacer;
	t_list	*prochain_maillon;

	a_effacer = *alst;
	while (a_effacer)
	{
		prochain_maillon = a_effacer->next;
		del(a_effacer->content, a_effacer->content_size);
		free(a_effacer);
		a_effacer = prochain_maillon;
	}
	*alst = NULL;
}
