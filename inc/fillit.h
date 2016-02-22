/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:28:20 by ahoareau          #+#    #+#             */
/*   Updated: 2016/02/22 17:48:41 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

# define BUF_SIZE 1
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "../../libft/libft.h"

int		open_close(char *file);
int		ft_sqrt(int nb);
void	display_square(int res);
void	ft_putchar(char c);

#endif
