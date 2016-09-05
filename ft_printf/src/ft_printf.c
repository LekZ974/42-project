/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 16:37:59 by ahoareau          #+#    #+#             */
/*   Updated: 2016/06/24 17:20:48 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_form			form;
	va_list			vl;

	form->str = format;
	if (!form)
	{
		ft_putendl("format string must be valid\n");
		exit (1);
	}
	va_start(vl, form->str);
	handle_format(form->str, vl);
	va_end(vl);
	return (0);
}
//utiliser aussi type va_arg(vl, "type") pour les arguments appeler
