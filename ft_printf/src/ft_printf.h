/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 12:25:59 by ahoareau          #+#    #+#             */
/*   Updated: 2016/08/04 17:06:30 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "libft.h"
#include <stdarg.h>

typedef struct		s_form
{
	const char		*str;
	size_t			location;//pour se deplacer sur str de format
}					t_form;

int		ft_printf(const char *format, ...);
void	handle_format(const char *form, va_list vl);//manipule le format et affiche
void	parse_form(t_form form->str, va_list vl);//analyse le format apres %

#endif
