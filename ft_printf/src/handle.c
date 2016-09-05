/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 13:41:06 by ahoareau          #+#    #+#             */
/*   Updated: 2016/06/24 16:45:20 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_format(t_form form->str, va_list vl)
{
	while ()
	{
		if (*form->str == %)
			parse_form(form->str, vl);//va analyser le flag % pour faire conversion
		ft_putchar(form->str);
		form->location++;
	}
}
