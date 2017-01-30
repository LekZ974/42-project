/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 16:45:50 by ahoareau          #+#    #+#             */
/*   Updated: 2016/08/12 15:35:47 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_form(t_form form->str, va_list vl)
{
	if ('s')//string
	{
		
	}
	if ('S')//wchar_t ??
	{
	}
	if ('p')//void
	{
	}
	if ('d' || 'D' || 'i')//int
	{
	}
	if ('o')//??
	{
	}
	if ('O')//??
	{
	}
	if ('u')//int
	{
	}
	if ('U')//int
	{
	}
	if ('x')// int vers hexa
	{
	}
	if ('X')// int vers hexa maj
	{
	}
	if ('c')//int
	{
	}
	if ('C')//wchar_t ??
	{
	}
	if ('%')
	{
	}
	else
		ft_putendl("incomplete format specifier\n");
}
